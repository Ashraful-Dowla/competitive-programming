/*
https://codeforces.com/contest/287/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

char str[5][5];

int calc(int i_s, int i_e, int j_s,int j_e){
	int cnt=0;
	for(int i=i_s;i<=i_e;++i){
		for(int j=j_s;j<=j_e;++j){
			if(str[i][j]=='.') cnt++;
		}
	}
	return cnt!=2;
}

int main(){
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			cin>>str[i][j];
		}
	}

	bool isPossible=false;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			isPossible|=calc(i,i+1,j,j+1);
		}
	}

	cout<<(isPossible? "YES": "NO")<<endl;

}