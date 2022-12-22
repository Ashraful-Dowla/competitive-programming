/*
https://codeforces.com/problemset/problem/1005/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	string s,t;
	cin>>s>>t;

	int sz_s=s.size();
	int sz_t=t.size();

	int diff = sz_s-sz_t;
	int total=sz_t+sz_s;
	if(diff!=0){
		if(diff<0){
			for(int i=0;i<abs(diff);++i){
				s='_'+s;
			}
		}
		else {
			for(int i=0;i<abs(diff);++i){
				t='_'+t;
			}
		}
	}

	for(int i=s.size()-1;i>=0;i--){
		if(s[i]==t[i]) total-=2;
		else break;
	}

	cout<<total<<endl;
}