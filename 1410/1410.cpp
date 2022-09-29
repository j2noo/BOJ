#include<iostream>
#include<string.h>
#include<string>
#include<set>
#define MOD 1000003
using namespace std;
int N,K;
char str[15][51];
int selected[1<<15]={0};
set<string> s;
int ans=0;
int len;
void solve(int bit){
  char ansStr[61]="??????????????????????????????????????????????????";
  
  for(int i=0;i<N;i++){
    if((bit & 1<<i)==0) //i 번째 비트 선택x
      continue;
    for(int j=0;j<len;j++){
      if(str[i][j]==ansStr[j]) // 두 글자가 같으면 그대로놔둠
        continue;
      if(str[i][j]!='?' && ansStr[j]!='?') // 두 글자가 다른데 물음표가 둘다아니면 패턴일치불가
        return;
      if(ansStr[j]=='?' )
        ansStr[j]=str[i][j];
    }
  }
  cout<<"ansstr : "<<ansStr<<endl;
  s.insert(ansStr);
  
}
int recur(int cnt, int idx,int bit){ //idx까지 선택된 인덱스와 선택된bit
  if(idx==N-1){

    if(cnt==K)
      selected[bit]=1;  //해당 선택비트 1로 설정
    return -1;
  }
  recur(cnt,idx+1,bit); //다음비트 선택안함
  recur(cnt+1,idx+1,bit | 1<<(idx+1)); //다음비트 선택
  return 0;
}
int main(){

  cin>>N>>K;
  for(int i=0;i<N;i++){
    cin>>str[i];
  }
  len=strlen(str[0]);

  recur(0,-1,0);

  for(int i=0;i< 1<<N; i++){
    if(selected[i]){
      solve(i);
    }
  }
  for(string str : s){
    cout<<str<<endl;
    int cntQ=1;
    
    for(int i=0;i<len;i++){
      if(str[i]=='?'){
        cntQ*=26;
        cntQ%=MOD;
      }
    }
    ans+=cntQ;
    ans%=MOD;
  }
  cout<<ans;
}