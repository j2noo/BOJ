#include<iostream>
#include<string.h>
#define ll long long
using namespace std;
int N,M,T;
ll dp[31][31];
ll solve(int n,int m){

  if(n==N-1) 
    return 1;
  int left= N-n-1;
  ll &ret=dp[n][m];
  if(ret!=-1) return ret;
   ret=0;
  for(int i=m+1;i<M;i++){
    ret+=solve(n+1,i);
  }
  return ret;
}
int main(){
  cin>>T;
  while(T--){
    cin>>N>>M;
    memset(dp,-1,sizeof(dp));
    ll ans=0;
    for(int i=0;i<M;i++){
      ans+=solve(0,i);
    }
    cout<<ans<<endl;
  }
  
}

