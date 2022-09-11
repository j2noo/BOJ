#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,M,R;
int depth=1;
vector<int> v[100003];
int visited[100003]={0};
int ans[100003]={0};
void dfs(int node){
  //cout<<node<<endl;
  visited[node]=1;
  ans[node]=depth++;
  for(int i=0;i<v[node].size();i++){
    int dest=v[node][i];
    if(visited[dest]==0){
      dfs(dest);
    }
  }
}
int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>N>>M>>R;
  int a,b;
  for(int i=0;i<M;i++){
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for(int i=1;i<=N;i++){
    sort(v[i].begin(),v[i].end());
  }
  dfs(R);
  for(int i=1;i<=N;i++){
    cout<<ans[i]<<"\n";
  }

}

