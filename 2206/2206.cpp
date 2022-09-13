#include<iostream> //2206
#include<queue>
#define piii pair<pair<int,int>,int> //(r,c),벽부쉈는지 여부
#define mp make_pair
using namespace std;
int N,M,K;
int arr[1001][1001];
int visited[11][1001][1001]={0};
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int bfs(){
  queue<piii> q;
  int depth=1;
  q.push(mp(mp(0,0),0));
  visited[0][0][0]=1;
  while(!q.empty()){
    int qs=q.size();
    for(int i=0;i<qs;i++){
      piii deq=q.front();
      q.pop();
      if(deq.first.first==N-1 && deq.first.second==M-1)
        return depth;
      for(int j=0;j<4;j++){
        int nr=deq.first.first+dy[j];
        int nc=deq.first.second+dx[j];
        if(nr<0 || nc<0 || nr>=N || nc>=M)
          continue;
        if(deq.second<K && arr[nr][nc]==1 && visited[deq.second+1][nr][nc]==0){ //부수자
          q.push(mp(mp(nr,nc),deq.second+1));
          visited[deq.second+1][nr][nc]=1;
        }
        if(arr[nr][nc]==0 && visited[deq.second][nr][nc]==0 ){ //갈수잇음
          q.push(mp(mp(nr,nc),deq.second));
          visited[deq.second][nr][nc]=1;
        }
      }
    }
    depth++;
  }
  return -1;
}
int main(){
  scanf("%d %d %d",&N,&M,&K);
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      scanf("%1d",&arr[i][j]);
    }
  }
  printf("%d",bfs());
}