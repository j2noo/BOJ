#include<iostream>
#define MOD 9901
using namespace std;
int dp[100001][3]={0};
int n;
int main(){
    cin>>n;
    for(int i=0;i<3;i++) dp[1][i]=1;
    for(int i=2;i<=100000;i++){
        dp[i][0]=dp[i-1][1]+dp[i-1][2];
        dp[i][1]=dp[i-1][0]+dp[i-1][2];
        dp[i][2]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
        for(int j=0;j<3;j++)
            dp[i][j]%=MOD;
    }
    cout<<(dp[n][0]+dp[n][1]+dp[n][2])%MOD;
}
