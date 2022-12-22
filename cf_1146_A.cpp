/*
https://codeforces.com/contest/1146/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int a=0;
	int sz = s.size();
	for(int i=0;i<sz;++i){
		if(s[i]=='a') a++;
	}

	if(a>(sz/2)) cout<<sz<<endl;
	else cout<<2*a-1<<endl;
}