#include<iostream>
#include<queue>
#include<utility>
#include<string.h>

using namespace std;
const int dy[4]={-1,0,1,0};
const int dx[4]={0,1,0,-1};
int w,h;
char arr[21][21];
int visited[1<<10][21][21];
int cnt=0;

typedef struct info{
  int bit;
  int r;
  int c;
}info;

int bfs(int r,int c){
  int depth=0;
  info initInfo = {0,r,c};
  queue<info> q;
  q.push(initInfo);
  visited[0][r][c]=1;

  while(!q.empty()){
    int qs=q.size();
    for(int i=0;i<qs;i++){
      info deq=q.front();
      q.pop();
      if(deq.bit== (1<<cnt) -1){
        return depth;
      }
      for(int j=0;j<4;j++){
        int nr=deq.r+dy[j];
        int nc=deq.c+dx[j];
        if(nr<0 || nc<0 || nr>=h | nc>=w || arr[nr][nc]=='x')
          continue;
        if(visited[deq.bit][nr][nc]==1) //현재 단계에서 방문
          continue;
        char dest = arr[nr][nc];
    
        info newInfo;
        if(dest>=0 && dest<=9){ //더러운곳 

          /*
          if(deq.bit & 1<<dest) //지금까지 방문한 더러운곳은 갈필요 없다
            continue;           //방문한 더러운곳을 다시 되돌아가는경우가있음.
          */

          //방문한적없는 더러운곳
          newInfo = {deq.bit | 1<<dest, nr, nc};
        }
        else { //방문한적없는 일반 땅
          newInfo = {deq.bit, nr, nc};
        }
        q.push(newInfo);
        visited[newInfo.bit][newInfo.r][newInfo.c]=1;
      }
    }
    depth++;
  }
  return -1;
}

int main(){
  int sr,sc;
  while(1){
    cnt=0;
    cin>>w>>h;
    if(!w)
      return 0;
    
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        cin>>arr[i][j];
        if(arr[i][j]=='o')
          sr=i,sc=j;
        if(arr[i][j]=='*')
          arr[i][j]=cnt++;
      }
    }
    memset(visited,0,sizeof(visited));
    cout<<bfs(sr,sc)<<endl; 
  }
}