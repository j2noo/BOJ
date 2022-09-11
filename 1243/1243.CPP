#include<iostream>
#include<string>
#include<String.h>
#include<vector>
using namespace std;
vector<string> v;
int N,L;
int main(){
    cin>>N>>L;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        v.push_back(str);
    }
}