#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,C;
vector<int> house,diff;
int check(int n){
    int sum=0;
    int cnt=1; //처음
    for(int i=0;i<N-1;i++){
        sum+=diff[i];
        if(sum>=n){
            sum=0;
            cnt++;
        }
    }
    //printf("거리%d로 공유기 %d개설치가능\n",n,cnt);
    return cnt>=C;
}
int main(){
    cin>>N>>C;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        house.push_back(tmp);
    }
    sort(house.begin(),house.end());
    for(int i=1;i<N;i++)
        diff.push_back(house[i]-house[i-1]);
    /*for(int i=0;i<diff.size();i++)
        cout<<diff[i];*/

    int lo=0, hi=(house[N-1]-house[0])+10;
    while(lo+1<hi){
        int mid=(lo+hi)/2;
        int ret=check(mid);
        if(ret){
            lo=mid;
        }
        else
            hi=mid;
    }
    printf("%d",lo);
}