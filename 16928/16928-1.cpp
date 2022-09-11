#include<iostream>
#include<queue>
using namespace std;
int N,M;
int warp[101]={0};
int visited[101]={0}; 

int bfs(){
  int depth=0;
  queue<int> q;
  q.push(1);
  visited[1]=1;
  while(!q.empty()){
    int qs=q.size();
    for(int i=0;i<qs;i++){
      int deq=q.front();
      q.pop();
      if(deq==100){
        return depth;
      }
      for(int j=1;j<=6;j++){
        if(visited[deq+j]==0){
          q.push(warp[deq+j]);
          visited[deq+j]=1;
        }
      }
    }
    depth++;
  }
  return 987654321;
}
int main(){
  cin>>N>>M;
  int x,y;
  for(int i=1;i<=100;i++)
    warp[i]=i;
  for(int i=0;i<N+M;i++){
    cin>>x>>y;
    warp[x]=y;
  }
  cout<<bfs();

}