#include<iostream>
#include<string.h>
#define INF 987654321
using namespace std;
int N,M;
int isnt[10001]={0};
int dp[11001][200];
int dx[3]={-1,0,1};
int solve(int n,int jump){ //n번돌로 jump만큼 뛰어서 이동했을 때 경우의수
    int &ret=dp[n][jump];
    if(ret!=-1) return ret;
    if(n==N) return ret=0;
    if(n>N) return ret=INF;
    ret=INF;
    for(int i=0;i<3;i++){
        int njump=jump+dx[i];
        if(njump<=0) continue;
        int nx=n+njump;
        if(isnt[nx])
            continue;
        ret=min(ret,solve(nx,njump)+1);
    }
    return ret;
}
int main(){
    cin>>N>>M;
    int tmp;
    for(int i=0;i<M;i++){
        cin>>tmp;
        isnt[tmp]=1; //py에서는어케
    }
    memset(dp,-1,sizeof(dp));
    int ans=solve(1,0);
    if(ans==INF) cout<<"-1";
    else cout<<ans;
}