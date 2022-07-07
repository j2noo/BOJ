#include<iostream>
#include<string.h>
#include<vector>
#include<utility>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int n,m,k;
int isNotRoad[101][101][2]={0}; //r,c에서 위,오른쪽으로 가는 도로존재여부
ll dp[101][101];
ll solve(int r,int c){// r,c에서 n,m까지 가는 경우의 수
    if(r>n || c>m) return 0;
    if(r==n && c==m) return 1;
    ll &ret=dp[r][c];
    if(ret!=-1) return ret;
    ret=0;

    if(isNotRoad[r][c][0]==0)
        ret+=solve(r+1,c);
    if(isNotRoad[r][c][1]==0)
        ret+=solve(r,c+1);
    return ret;
}
int main(){
    cin>>n>>m>>k;
    int a,b,c,d;
    for(int i=0;i<k;i++){
        cin>>a>>b>>c>>d;
        if(a==c){ //우로가는도로
            if(b<d) //(a,b)
                isNotRoad[a][b][1]=1;
            else   
                isNotRoad[c][d][1]=1;
        }
        else{ //위로가는도로
            if(a<c)
                isNotRoad[a][b][0]=1;
            else
                isNotRoad[c][d][0]=1;
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0);
}