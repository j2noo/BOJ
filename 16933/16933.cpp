#include<iostream> //16933
#include<queue>
#define piiii pair<pair<int,int>,pair<int,int>> //(r,c),(벽 부순 갯수, 낮밤01)
#define mp make_pair
using namespace std;
int N,M,K;
int arr[1001][1001];
int visited[11][1001][1001]={0};
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int bfs(){
  queue<piiii> q;
  int depth=1;
  q.push(mp(mp(0,0),mp(0,0)));
  visited[0][0][0]=1;
  while(!q.empty()){
    int qs=q.size();
    for(int i=0;i<qs;i++){
      piiii deq=q.front();
      q.pop();
      if(deq.first.first==N-1 && deq.first.second==M-1)
        return depth;
      for(int j=0;j<4;j++){
        int nr=deq.first.first+dy[j];
        int nc=deq.first.second+dx[j];
        if(nr<0 || nc<0 || nr>=N || nc>=M)
          continue;
        if(deq.second.first<K && arr[nr][nc]==1 && visited[deq.second.first+1][nr][nc]==0 && deq.second.second==0){ //부수자 낮에만
          q.push(mp(mp(nr,nc),mp(deq.second.first+1,1))); //밤 으로 추가
          visited[deq.second.first+1][nr][nc]=1;
        }
        if(arr[nr][nc]==0 && visited[deq.second.first][nr][nc]==0 ){ //갈수잇음
          int toggle= deq.second.second == 0 ? 1 : 0;
          q.push(mp(mp(nr,nc),mp(deq.second.first,toggle)));
          visited[deq.second.first][nr][nc]=1;
        }
      }
      if(deq.second.second==1){ //밤이면 머무르기, 낮에는 머무를 필요가없음
        int toggle= deq.second.second == 0 ? 1 : 0;
        q.push(mp(mp(deq.first.first,deq.first.second),mp(deq.second.first,toggle)));
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