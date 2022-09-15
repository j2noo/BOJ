#include<iostream>
#include<vector>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int arr[9][9];
int ansFlag=0;
vector<pii> v; //빈칸의 위치
int check(int r,int c){ //해당 칸에 가능한 숫자인지
  int num=arr[r][c];
  for(int row=0;row<9;row++){
    if(row==r)
      continue;
    if(arr[row][c]==num)
      return 0;
  }
  for(int col=0;col<9;col++){
    if(col==c)
      continue;
    if(arr[r][col]==num)
      return 0;
  }
  int row=r/3*3;
  int col=c/3*3;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      int nr=row+i;
      int nc=col+j;
      if(nr==r && nc==c)
        continue;
      if(arr[nr][nc]==num)
        return 0;
    }
  } 
  return 1;
}
void recur(int idx){ //벡터의 인덱스
  if(v.size()==idx){
    //printf("%d idx end",idx);
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
        cout<<arr[i][j]<<" ";
      }
      cout<<endl;
    }
    ansFlag=1;
    return;
  }
  int r=v[idx].first;
  int c=v[idx].second;
  for(int i=1;i<=9;i++){
    arr[r][c]=i;
    if(check(r,c) && !ansFlag){
      recur(idx+1);
    }
    arr[r][c]=0;
  }
}
int main(){
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      cin>>arr[i][j];
      if(arr[i][j]==0){
        v.push_back(mp(i,j));
      }
    }
  }

  recur(0);
}