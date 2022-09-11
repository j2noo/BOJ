#include<iostream>
#include<cstring>
#include<queue>
#include<utility>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int dy[8]={-1,-1,-1,0,1,1,1,0};
int dx[9]={-1,0,1,1,1,0,-1,-1};
int H,W;
int arr[1001][1001]={0}; //ans번째에 부서진 모래
queue<pii> q; //부서진곳 주변만 넣는 큐

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans=1,flag=0;
    char tmp;
    cin>>H>>W;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>tmp;
            if(tmp=='.') arr[i][j]=0;
            else arr[i][j]=-(tmp-'0');
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(arr[i][j]>=0 || arr[i][j]==-9) continue;
            int cnt=0;
            for(int k=0;k<8;k++){
                int ny=i+dy[k];
                int nx=j+dx[k];
                if(arr[ny][nx]>=0 && arr[ny][nx]!=ans) cnt++; //모래이면서 방금부서진게아님
            }
            if(cnt>= -arr[i][j]){ //부수자
                flag=1;
                arr[i][j]=ans;
                for(int k=0;k<8;k++){
                    int ny=i+dy[k];
                    int nx=j+dx[k];
                    if(arr[ny][nx]>=-8 && arr[ny][nx]<=-1){ //나보다 위,왼쪽인경우 존재하나?
                        q.push(mp(ny,nx));
                    }
                }
            }
        }
    }
    if(flag==0){
        cout<<"0";
        return 0;
    }

    flag=0;
    while(1){
        flag=0;
        ans++;
        int qs=q.size();
        for(int i=0;i<qs;i++){
            pii deq=q.front(); //한 depth에서 여러번 들어온 좌표가 부서지지 않는 경우 *8?
            int deqy=deq.first;
            int deqx=deq.second;
            q.pop();
          
            if(arr[deqy][deqx]>=0) continue; //q에 넣고보니 부서짐
           
            int cnt=0;
            for(int k=0;k<8;k++){
                int ny=deqy+dy[k];
                int nx=deqx+dx[k];
                if(arr[ny][nx]>=0 && arr[ny][nx]!=ans) cnt++;
            }
            
            if(cnt>= -arr[deqy][deqx]){ //부수자
                flag=1;
                arr[deqy][deqx]=ans;
                for(int k=0;k<8;k++){
                    int ny=deqy+dy[k];
                    int nx=deqx+dx[k];
                    if(arr[ny][nx]>=-8 && arr[ny][nx]<=-1) //나보다 위,왼쪽인경우 존재하나?
                        q.push(mp(ny,nx));
                }  
            }
        }
        if(flag==0) break;    
        
    }
    cout<<ans-1;
}