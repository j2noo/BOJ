#include<iostream>
#include<string.h>
using namespace std;
int n;
int arr[111][111],dp[111][111]; //ù����1?
int solve(int r,int c){ //r,c���� n-1,n-1�� �� �� �ִ� ����� ��
    int &ret=dp[r][c];
    if(ret!=-1) return ret;

    if(r>=n || c>=n) return ret=0;
    if(r==n-1 && c==n-1) return ret=1;
    
    int num=arr[r][c];
    if(num==0) return ret=0;
    return ret=solve(r+num,c)+solve(r,c+num);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0);
}