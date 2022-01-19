#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin>>n;
    vector<int> ships(n,0);
    
    for(int i=0;i<n;i++){
        cin>>ships[i];
    }
    sort(ships.begin(),ships.end());
    cin>>m;
    vector<int> boxes(m,0);
    for(int i=0;i<m;i++){
        cin>>boxes[i];
    }
    sort(boxes.begin(),boxes.end());

    if(boxes[m-1]>ships[n-1]){
        cout<<-1<<endl;
        return 0;
    }

    vector<int> ships_boxes(n,0);
    int j = 0;
    for(int i=0;i<m;i++){
        if(boxes[i] <= ships[j]){
            ships_boxes[j]++;
        }
        else{
            j++;
            i--;
        }
    }
    while (1)
    {
        int max_index = 0;
        for(int i=0;i<n;i++){
            if(ships_boxes[max_index]<=ships_boxes[i]){
                max_index = i;
            }
        }
        if(max_index==n-1){
            break;
        }
        else{
            ships_boxes[max_index]--;
            ships_boxes[max_index+1]++;
        }
    }
   cout<<*max_element(ships_boxes.begin(),ships_boxes.end())<<endl;
}