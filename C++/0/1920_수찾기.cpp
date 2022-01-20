#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n,0);
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int m;
    cin>>m;
    for(int mi=0; mi<m; mi++){
        int find;
        cin>>find;
        int start,end;
        start = 0;
        end = n-1;
        while(end>=start){
            int mid = (end+start)/2;
            if(v[mid] == find){
                cout<<1<<'\n';
                break;
            }
            else if(end==start){
                start+=1;
                break;
            }
            else if(v[mid]>find){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        if(end<start){
            cout<<0<<'\n';
        }
    }
}