#include<iostream> 
#include<utility>
#include<queue>
#include<string.h>
#include<tuple>
#define pii pair<int,int>
#define mp make_pair
#define mt make_tuple
#define INF 987654321
using namespace std;
typedef tuple<int,int,int> piii;
int arr[21][21];
int n;
int br,bc;
int bsize=2;
int dy[4]={-1,0,0,1};
int dx[4]={0,-1,1,0};
int bfs(){  //br,bcㅇ에서 가장 가까운고기
    int ret=0;
    int v[21][21]={0};
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    pq.push(mt(0,br,bc));
    v[br][bc]=1;
    while(!pq.empty()){
        int qs=pq.size();
        piii deq;
        for(int i=0;i<qs;i++)  {
            deq=pq.top();
            pq.pop();
            int deq1=get<0>(deq); //거리
            int deq2=get<1>(deq); //r
            int deq3=get<2>(deq); //c
            if(arr[deq2][deq3]<bsize && arr[deq2][deq3]>0){ //먹을수
                arr[br][bc]=0;
                br=deq2;
                bc=deq3;
                arr[br][bc]=999;
                return ret;
            } 
            for(int j=0;j<4;j++){
                int nr=deq2+dy[j];
                int nc=deq3+dx[j];
                if(nr<0 || nc<0 || nr>=n || nc>=n)
                    continue;
                if(arr[nr][nc]<=bsize && v[nr][nc]==0){ //방문가능
                    pq.push(mt(ret+1,nr,nc));
                    v[nr][nc]=1;
                }
            }
        }
        ret++;
    }
    return INF;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]==9)
                br=i,bc=j,arr[i][j]=999;
        }
    }
    int ans=0;
    int eatedCnt=0;
    while(1){
        int calc=bfs(); //가장 가까운거리
        if(calc==INF) break; //못찾음
        ans+=calc;
        eatedCnt++;
        if(eatedCnt==bsize)
            eatedCnt=0,bsize++;
    }
    cout<<ans;
    return 0;
}   