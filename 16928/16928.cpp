#include<iostream>
using namespace std;
int N,M;
int warp[101]={0};
int dp[101]={0}; //idx에서 100번으로 이동하는 최소횟수
int solve(int idx){
  int ret=0;
  for(int i=idx+1; i<=idx+6;i++){
    if(i>100) return 0;
    ret=min(ret,solve(i)+1); //뱀타고 내려갈때 무한루프 //비트마스킹??
  }
}
int main(){
  cin>>N>>M;
  int x,y;
  for(int i=0;i<N;i++){
    cin>>x>>y;
    warp[x]=y;
  }
  for(int i=0;i<M;i++){
    cin>>x>>y;
    warp[x]=y;
  }
  cout<<solve(1);
  
}