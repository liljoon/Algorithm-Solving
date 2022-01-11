#include<iostream>
using namespace std;

int map[20]={ -1 };
int cnt = 0;
int n;

void solve(int p){
    if(p>=n){
        
        cnt++;
        return;
    }
    for(int i=0;i<p;i++){
        if(map[i] == map[p]){
            return;
        }
        if(map[i]+i == map[p]+p){
            return;
        }
        if(map[i]-map[p] == i-p){
            return;
        }
        if(map[p]-map[i] == p-i){
            return;
        }
    }
    if(p==n-1){
        cnt++;
        return;
    }
    for(int i=0;i<n;i++){
        map[p+1] = i;
        solve(p+1);
    }
}

int main(){
    
    cin>>n;
     for(int i=0;i<n;i++){
        map[i] = -1;
    }
    for(int i=0;i<n;i++){
        map[0] = i;
        solve(0);
    }
    cout<<cnt<<endl;
}