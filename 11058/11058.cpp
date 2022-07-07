#include<iostream>
#define ll long long
using namespace std;
int n;
ll dp[101]={0};
int main(){
    cin>>n;
    for(int i=1;i<=6;i++)
        dp[i]=i;
    for(int i=7;i<=100;i++)
        dp[i]=max(max(dp[i-3]*2,dp[i-4]*3),dp[i-5]*4);
    cout<<dp[n];
}