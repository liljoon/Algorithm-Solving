#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<int> dice(6,0);
    for(int i=0;i<6;i++){
        cin>>dice[i];
    }

    if(n==1){  //n이 1일때 예외처리
        int sum=0;
        for(int i=0;i<6;i++){
            sum+= dice[i];
        }
        sum -= *max_element(dice.begin(),dice.end());
        cout<<sum<<endl;
        return 0;
    }
    long long sum = 0;
    //한 면만 보이는 주사위 합
    sum += 4 * (n-2) * (n-1) * (*min_element(dice.begin(),dice.end())); // 옆면만
    sum += (n-2) * (n-2) * (*min_element(dice.begin(),dice.end())); //윗면만 
    
    //두 면 보이는 모서리 합 (n-1) * 4  + (n-2) * 4
    int min_two = 987654321;
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            if(i+j != 5){ //서로 마주보는 경우가 아닐 때
                min_two = min(min_two,dice[i]+dice[j]);
            }
        }
    }
    sum += min_two *((n-1) * 4  + (n-2) * 4);

    int min_three = 987654321;
    //세면 보이는 모서리 합 4개
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            for(int k=j+1;k<6;k++){
                if(i+j != 5 && j+k != 5 && i+k !=5){  //하나라도 마주보는 경우가 아닐때
                    min_three = min(min_three,dice[i]+dice[j]+dice[k]);
                }
            }
        }
    }
    sum += 4 * min_three;

    cout<<sum<<endl;
}
