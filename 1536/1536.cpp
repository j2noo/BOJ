#include<iostream>
#define MOD 1000000
using namespace std;
int dp[1001][2][3]={0}; //day, late, consAbs
int N;
void solve(){
  dp[1][0][0]=1;
  dp[1][1][0]=1;
  dp[1][0][1]=1;

  for(int i=2;i<=N;i++){
    //출석
    for(int j=0;j<3;j++){
      dp[i][0][0]+=dp[i-1][0][j];
      dp[i][1][0]+=dp[i-1][1][j];
      // 지각
      dp[i][1][0]+=dp[i-1][0][j];

      dp[i][0][0]%=MOD;
      dp[i][1][0]%=MOD;
    }
    //결석
    for(int j=1;j<3;j++){
      dp[i][0][j]+=dp[i-1][0][j-1];
      dp[i][1][j]+=dp[i-1][1][j-1];

      dp[i][0][j]%=MOD;
      dp[i][1][j]%=MOD;
    }
  }
}
int main(){
  cin>>N;
  solve();
  cout<<(dp[N][0][0]+dp[N][0][1]+dp[N][0][2]+
        dp[N][1][0]+dp[N][1][1]+dp[N][1][2])%MOD;
}
