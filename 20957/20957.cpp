#include<iostream>
#define MOD int(1e9)+7
using namespace std;
int T,N;
int dp[10001][7][2]={0}; //n자리, 합mod7, 7배수인가
void solve(){
  for(int i=2;i<=10000;i++){
    for(int j=0;j<7;j++){
      for(int k=0;k<=9;k++){ // 0 1 2 3 4 5 6 8 9

        //곱이 7배수 아닌수 -> 곱이 7배수인수
        if(k==7 || k==0){
          dp[i][(j+k) % 7][1]+=dp[i-1][j][0];
          dp[i][(j+k) % 7][1]%=MOD;
        }
        else {
          //곱이 7배수 아닌수 -> 곱이7배수 아닌수
          dp[i][(j+k) % 7][0]+=dp[i-1][j][0];
          dp[i][(j+k) % 7][0]%=MOD;
        }

        //곱이 7배수인수 -> 그대로 곱이 7배수
        dp[i][(j+k) % 7][1]+=dp[i-1][j][1];
        dp[i][(j+k) % 7][1]%=MOD;
      }
    }
  }
} 
int main(){
  cin>>T;

  dp[1][0][1]=1; //7
  dp[1][1][0]=2; //1 8
  dp[1][2][0]=2; //2 9
  dp[1][3][0]=1; //3 
  dp[1][4][0]=1; //4
  dp[1][5][0]=1; //5
  dp[1][6][0]=1; //6
  
  solve();

  while(T--){
    cin>>N;
    cout<<dp[N][0][1]<<endl;
  } 
}
