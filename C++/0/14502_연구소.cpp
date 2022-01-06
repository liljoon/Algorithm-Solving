#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N,M;
vector<vector<int>> v;
queue<pair<int,int>> que;
vector<int> ans;



int bfs_setting(){
    vector<vector<int>> bmap(N,vector<int>(M,-1));
    vector<vector<int>> vst(N,vector<int>(M,0));
    while(!que.empty()){
        que.pop();
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            bmap[i][j] = v[i][j];
            if(bmap[i][j]==2){
                que.push(make_pair(i,j));
            }
        }
    }

    
    while(!que.empty()){
        int y = que.front().first;
        int x = que.front().second;
        que.pop();
        if(y<0 || y>=N || x<0 || x>=M){
            continue;
        }
        if(bmap[y][x]==1 || vst[y][x]==1){
            continue;
        }
        bmap[y][x] = 2;
        vst[y][x] = 1;
        que.push(make_pair(y,x+1));
        que.push(make_pair(y,x-1));
        que.push(make_pair(y-1,x));
        que.push(make_pair(y+1,x));
    }
    int count = 0;
   for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(bmap[i][j]==0){
                count++;
            }
        }
    }
    return count;
}

int solve(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
};

int wall(int y,int x,int idx){
    if(idx==3){
        return bfs_setting();
    }
    if(y>=N || x>= M){
        return 0;
    }
    int a;

    if(x+1 != M){
        a = wall(y,x+1,idx);
    }
    else{
        a = wall(y+1,0,idx);
    }
    int b = 0;
    if(v[y][x] == 0){
        v[y][x] = 1;
         if(x+1 != M){
            b = wall(y,x+1,idx+1);
        }
        else{
            b = wall(y+1,0,idx+1);
        }
        v[y][x]  = 0;
    }
    return (a > b) ? a:b;
    
}

int main(){
    cin>>N>>M;
    v = vector<vector<int>>(N,vector<int>(M,-1));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>v[i][j];
        }
    }
    cout<<wall(0,0,0)<<endl;
}