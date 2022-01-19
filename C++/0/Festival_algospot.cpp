#include<iostream>
#include<vector>
using namespace std;

int main(){
    int c;
    cin>>c;
    for(int ci=0;ci<c;ci++){
        int n;
        cin>>n;
        int l;
        cin>>l;
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        double ans = 999999;
        for(int i=0;i<=n-l;i++){
            for(int j=i+l;j<=n;j++){
                double pay = 0;
                for(int t = i;t<j;t++){
                    pay += v[t];
                }
                pay = pay / (j-i);
                if (pay < ans){
                    ans = pay;
                }
            }
        }
        cout<<fixed;
        cout.precision(10);
        cout<<ans<<endl;
    }

}