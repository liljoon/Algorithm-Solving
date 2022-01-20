#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n,S;
    cin>>n;
    cin>>S;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    int start = 0;
    int end = 0;
    int sum = 0;
    while (sum<S){
        if(end >= n){ //전부 합쳐도 안될 때
            cout<<0<<endl;
            return 0;
        }
        sum+= v[end];
        end++;
    }
    int length_min = end-start;
    while(true){
        while(true){ // 앞에 땡김
            if(sum-v[start]<S){
                break;
            }
            sum -= v[start];
            start++;
        }
        length_min = min(length_min,end-start);
        //뒤에 밀기
        if(end==n){ // 더 이상 미룰 곳이 없을 경우 종료
            break;
        }
        sum += v[end];
        end++;
    }
    cout<<length_min<<endl;

}