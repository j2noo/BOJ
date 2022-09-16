#include<iostream>
#include<queue>
#include<string.h>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int T,A,B;
int visitedFrom[10001];
int convertedBy[10001];
int DSLR(char ch, int num){
  if(ch==0){ //D
    return num*2%10000;
  }
  else if(ch==1) { //S
    return (num+9999) %10000;
  }
  else if(ch==2) { //L
    return (num%1000 *10) + (num/1000);
  }
  //R
  return (num%10 *1000) + (num/10);
  
}
void backTrack(){
  int num=B;
  char dslr[4]={'D','S','L','R'};
  vector<char> ans;
  while(num!=A){
    ans.push_back(dslr[convertedBy[num]]);
    num=visitedFrom[num];
  }
  int vs=ans.size();
  for(int i=vs-1;i>=0;i--)
    cout<<ans[i];
  cout<<endl;
}
void bfs(){
  queue<int> q;
  int depth=0;
  q.push(A);
  visitedFrom[A]=-2;

  while(!q.empty()){
    int qs=q.size();
    for(int i=0;i<qs;i++){
      int deq=q.front();
      q.pop();
      if(deq==B){
        backTrack();
        return;
      }
      for(int j=0;j<4;j++){
        int conv=DSLR(j,deq);
        if(visitedFrom[conv]==-1){
          visitedFrom[conv]=deq;
          convertedBy[conv]=j;
          q.push(conv);
        }
      }
    }
    depth++;
  }
}
int main(){
  cin>>T;
  while(T--){
    memset(visitedFrom,-1,sizeof(visitedFrom));
    memset(convertedBy,-1,sizeof(convertedBy));
    cin>>A>>B;
    bfs();
    cout<<endl;
  }
}