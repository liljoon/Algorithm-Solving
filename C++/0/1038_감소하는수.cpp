#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int count = -1;
    long long i = 0;
    
    while(count<n){
        
        if(i>9876543210){
            i = 0;
            break;
        }
        bool chk = true;
        string temp = to_string(i); // 문자열로 변환하여 저장
        int j=0;
        for(j=0;j<temp.size()-1;j++){  // 증가하는 부분이 있는지 체크 있으면 j로 위치 저장해놈
            if(temp[j]<=temp[j+1]){
                chk = false;
                break;
            }
        }


    
        if(chk == true){ // 감소하는 수이면 증가시키고 숫자하나 넘김
            count++;
            i++;
        }
        else{ // 증가하는 부분에서 앞자리는 하나 증가시키고 뒷자리 밑으로는 전부 0으로 만들어줌
            int point = temp.size()-j;
            int p = pow(10,point-1);
            i += p;
            i = i - i % p;
        }
        
    }
    cout<<i-1<<endl; //최종에 i++가 진행되었기 때문에 1을 뺀 수를 출력
}