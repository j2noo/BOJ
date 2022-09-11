#include<iostream>
#include<utility>
#include<cstring>
#include<string.h>
using namespace std;
int N,M;
int arr[400][400],nextArr[400][400];
int visit[400][400];
int dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
void dfs(int r,int c){
    int nr,nc;
    for(int i=0;i<4;i++){
        nr=r+dy[i],nc=c+dx[i];
        if(arr[nr][nc]==0)
            nextArr[r][c]=max(0,nextArr[r][c]-1);
        
        else if(visit[nr][nc]==0){
            visit[nr][nc]=1;
            dfs(nr,nc);
        }
    }
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
            nextArr[i][j]=arr[i][j];
        }
    }
    int ans=0;
    while(2){
        memset(visit,0,sizeof(visit));
        int cnt=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(arr[i][j]>0 && visit[i][j]==0){
                    visit[i][j]=1;//wow¼ø¼­
                    dfs(i,j); //wow
                    cnt++;
                }
            }
        }
        if(cnt>=2){
            cout<<ans;
            return 0;
        }
        if(cnt==0){
            cout<<"0";
            return 0;
        }
        ans++;
        memcpy(arr,nextArr,sizeof(arr));
    }
    
    
}