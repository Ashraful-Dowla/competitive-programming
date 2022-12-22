/*
https://codeforces.com/problemset/problem/1189/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;

	int cnt_0=0,cnt_1=0;

	for(int i=0;i<n;++i){
		if(s[i]=='1') cnt_1++;
		else cnt_0++;
	}

	if(cnt_0!=cnt_1) {
		cout<<1<<endl;
		cout<<s<<endl;
	}
	else {
		cout<<2<<endl;
		cout<<s[0]<<" ";
		for(int i=1;i<n;++i) {
			cout<<s[i];
		}
		cout<<endl;
	}
}		