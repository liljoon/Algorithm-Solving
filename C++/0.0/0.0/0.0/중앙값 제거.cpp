#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v1,v2;
    int N;
    cin>>N;
    for(int i =0;i<N;i++){
        int a;
        cin>>a;
        v1.push_back(a);
    }
    sort(v1.begin(),v1.end());
    for(int i=0;i<(N+1)/2;i++){
        v2.push_back(v1[i]);
    }
    int count = 0;

    for(int i=0;i<v2.size();i++){
        int last = v2[i];
    
        while(true){
            if(last==1){
                break;
            }
            last = last/2;
            count++;

        }
    }

    cout<<count+1<<endl;

}