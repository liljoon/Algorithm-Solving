#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,m,b;
    cin>>n>>m>>b;
    vector<vector<int>> v(n,vector<int>(m,0));
    int down=999,up=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            down = min(v[i][j],down);
            up = max(v[i][j],up);
        }
    }
    int min_time=987654321,height;
    for(int i=down;i<=up;i++){      //가장 낮은 높이부터 가장 높은 블럭까지 전부 브루트포스
        int cut=0,build=0;
        for(int y=0;y<n;y++){
            for(int x=0;x<m;x++){
                if(v[y][x]-i < 0){
                    build += i -v[y][x]; //쌓아야하는 블럭의 개수
                }
                else{
                    cut += v[y][x]-i;  // 파야하는 블럭의 개수
                }
            }
        }
        if(build - cut <= b){ // 들고 있는 블럭보다 쌓을게 더 많지 않다면
            if(min_time >= build+cut*2){
                min_time = build+cut*2;
                height = i;
            }
        }

    }
    cout<<min_time<<" "<<height<<endl;
}