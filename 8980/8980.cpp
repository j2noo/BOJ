#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<tuple>
#define mp make_pair
#define pii pair<int,int>
#define tdiii tuple<double,int,int,int>
using namespace std;
int N,M,C;
int arr[2001][2001]={0};
double value[2001][2001]={0};
vector<tdiii> tv;
bool cmp(tdiii t1,tdiii t2){
    return get<0>(t1)>get<0>(t2);
}
int main(){
    cin>>N>>C>>M;
    for(int i=0;i<M;i++){
        int from,dest,ea;
        cin>>from>>dest>>ea;
        tv.push_back(make_tuple(double(ea)/(dest-from),from,dest,ea));
    }
    
    sort(tv.begin(),tv.end(),cmp);
    for(int i=0;i<tv.size();i++){
        printf("%f %dto %d, %dEA\n",get<0>(tv[i]),get<1>(tv[i]),get<2>(tv[i]),get<3>(tv[i]));
    }

    int ans=0;
    int cap[2001]={0}; //i번마을에서의 용량
    for(int i=0;i<tv.size();i++){
        int toLoad=987654321;
        for(int j=get<1>(tv[i]);j<get<2>(tv[i]);j++){
            toLoad=min(toLoad,min(C-cap[j],get<3>(tv[i])));
        }
        if(toLoad>0){
            for(int j=get<1>(tv[i]);j<get<2>(tv[i]);j++){
                cap[j]+=toLoad;
            }
            ans+=toLoad;
        }
        
        printf("%dto %d %dEA실음\n",get<1>(tv[i]),get<2>(tv[i]),toLoad);
    }
    cout<<ans;
}