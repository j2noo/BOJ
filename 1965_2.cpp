#include<iostream>
#include<string.h>
using namespace std;
int n;
int arr[1001],dp[1011][1111];
int solve(int idx,int before){ //idx에서, 이전이 before일때 최대고루는개수
    int &ret=dp[idx][before];
    if(ret!=-1) return ret;
    if(idx==n-1) return 0;
    ret=solve(idx+1,before); //다음거 안고름
    if(arr[idx+1]>before)
        ret=max(ret,solve(idx+1,arr[idx+1])+1); //다음거 고름
    return ret;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    cout<<max(solve(0,0),solve(0,arr[0])+1)<<endl;
}