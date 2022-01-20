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

    if(boxes[m-1]>ships[n-1]){ // 박스의 최대값이 배의 최대값을 넘어설 경우
        cout<<-1<<endl;
        return 0;
    }

    vector<int> ships_boxes(n,0);
    int j = 0;
    for(int i=0;i<m;i++){ // ship_boxes는 각 배가 낮은 순서로 최대로 가져갔을 경우 들 수 있는 박스 수
        if(boxes[i] <= ships[j]){
            ships_boxes[j]++;  // 들 수 있을 경우 카운트
        }
        else{ //들 수 없을 경우 다음 배로 확인하는데 방금 박스도 다시 확인해야 하므로 i--까지
            j++;
            i--;
        }
    }
    while (1) // 가장 오래 걸리는 배를 오른쪽으로 박스 하나씩 계속 미뤄주면서 만약 더이상 미룰 수 없는 경우 break
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
   cout<<*max_element(ships_boxes.begin(),ships_boxes.end())<<endl;// 최대로 들고 있는 경우가 걸리는 시간
}