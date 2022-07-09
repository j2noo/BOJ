#include<iostream>
#include<string.h>
using namespace std;
int n;
int arr[1001],dp[1011];
int solve(int num){ //i를 선택했을때 n까지 최대
    int &ret=dp[num];
    if(ret!=-1) return ret;
    ret=1;
    for(int i=num+1;i<n;i++){
        if(arr[i]>arr[num])
            ret=max(ret,solve(i)+1);
    }
    return ret;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,solve(i));
    }
    cout<<ans;
    
}