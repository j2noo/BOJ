#include<iostream>
#include<string.h>
#include<vector>
#define MOD 999983
using namespace std;
int K;
string str;
vector<long long> vnum;
long long sum[101][10000]={0};  //sum[i][j]는 총 i개의 숫자의 합이 j인 개수
long long calc1(){
    long long ret=0;
    for(int i=0;i<10000;i++){
        if(sum[K][i]>0)
            ret+=sum[K][i]*sum[K][i];
        ret%=MOD;
    }
    return ret;
}
long long calc3(){
    long long ret1=0,ret2=0;
    for(int i=0;i<10000;i++){
        if(sum[(K+1)/2][i]>0)
            ret1+=sum[(K+1)/2][i]*sum[(K+1)/2][i];
        ret1%=MOD;
    }
    for(int i=0;i<10000;i++){
        if(sum[K/2][i]>0)
            ret2+=sum[K/2][i]*sum[K/2][i];
        ret2%=MOD;
    }
    return (ret1*ret2)%MOD;
}
int main(){
    cin>>K;
    cin>>str;
    if(K==1){
        cout<<str.length();
        return 0;
    }
    for(int i=0;i<str.length();i++){
        vnum.push_back(str[i]-'0');
        sum[1][str[i]-'0']=1;
    }
    for(int i=2;i<=K;i++){ //k자리 가능한 합의 개수
        for(int j=0;j<10000;j++){
            for(int k=0;k<vnum.size();k++){
                if(sum[i-1][j]>0)
                    sum[i][j+vnum[k]]+=sum[i-1][j];
                sum[i][j]%=MOD;
            }
        }
    }
        cout<<(calc1()*2+MOD-calc3())%MOD;
}