#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n;
int adj[51][51]={0};
void bfs(int p){
    int v[51]={0};
    int depth=0;
    queue<int> q;
    q.push(p);
    v[p]=1; 

    while(!q.empty()){
        int qs=q.size();
        for(int i=0;i<qs;i++){
            int deq=q.front();
            q.pop();
            adj[p][deq]=adj[deq][p]=depth;
            for(int j=1;j<=n;j++){
                if(adj[deq][j]==1 && v[j]==0){
                    q.push(j);
                    v[j]=1;
                }
            }
        }
        depth++;
    }
}
int main(){
    cin>>n;
    int p1,p2;
    while(1){
        cin>>p1>>p2;
        if(p1==-1) break;
        adj[p1][p2]=adj[p2][p1]=1;
    }
    for(int i=1;i<=n;i++)
        bfs(i);
    int ans=987654321;
    int score[51]={0};
    vector<int> cand;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            score[i]=max(score[i],adj[i][j]);
        ans=min(ans,score[i]);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(ans==score[i]){
            cnt++;
            cand.push_back(i);
        }
    }
    cout<<ans<<" "<<cnt<<endl;
    for(int i=0;i<cand.size();i++)
        cout<<cand[i]<<" ";
    return 0;
}