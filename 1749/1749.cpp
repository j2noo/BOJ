#include<iostream>
using namespace std;
int N,M;
int arr[202][221];
int dp[202][202]={0}; //´©ÀûÇÕ
int main(){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        int psum=0;
        for(int j=1;j<=M;j++){
            cin>>arr[i][j];
            psum+=arr[i][j];
            dp[i][j]=dp[i-1][j]+psum;
        }
        
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
}