/*
https://codeforces.com/contest/43/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	string h,t;
	getline(cin,h);
	getline(cin,t);

	int hsh[130];
	memset(hsh,0,sizeof(hsh));

	for(int i=0;i<h.size();++i){
		hsh[h[i]-'A']++;
	}

	bool ok=true;
	for(int i=0;i<t.size();++i){
		if(t[i]==' ') continue;
		if(hsh[t[i]-'A']==0){
			ok=false;
			break;
		}
		hsh[t[i]-'A']--;
	}

	cout<<(ok ? "YES":"NO")<<endl;
}