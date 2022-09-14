#include<iostream>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
int N,M;
int arr[1001][1001];
int idx=0;
vector<int> cntVector;
int cnt=0;

int visited[1001][1001]={0};
int idxArr[1001][1001];

const int dy[4]={-1,0,1,0};
const int dx[4]={0,1,0,-1};

int dfs(int r,int c,int idx){ //빈칸인곳들 크기 계산 // 센 개수 반환
  cnt++;
  idxArr[r][c]=idx;
  visited[r][c]=1;
  for(int i=0;i<4;i++){
    int nr=r+dy[i];
    int nc=c+dx[i];
    if(nr<0 || nc<0 || nr>=N || nc >=M)
      continue;
    if(arr[nr][nc]==0 && visited[nr][nc]==0)
      dfs(nr,nc,idx);
  }
  return cnt;
}
int main(){
  memset(idxArr,-1,sizeof(idxArr));
  cin>>N>>M; 
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      scanf("%1d",&arr[i][j]);
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(visited[i][j]==0 && arr[i][j]==0){
        cnt=0;
        int tmp=dfs(i,j,idx++);
        cntVector.push_back(tmp);
      }
    }
  }

 for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      int sum=0;
      if(arr[i][j]==1){  //벽이면 부수자
        set<int> set; //중복제거
        sum+=1;
        for(int k=0;k<4;k++){
          int nr=i+dy[k];
          int nc=j+dx[k];
          if(nr<0 || nc<0 || nr>=N || nc >=M || arr[nr][nc]==1)
            continue;
          set.insert(idxArr[nr][nc]);
        }
        for(int i : set){
          sum+=cntVector[i];
        }
      }
      printf("%d",sum%10);
    }
    printf("\n");
  }
}