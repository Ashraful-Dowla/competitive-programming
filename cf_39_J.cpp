/*
https://codeforces.com/contest/39/problem/J
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	string s,t;
	cin>>s;
	cin>>t;

	int l,r;
	for(l=0;s[l]==t[l];l++);

	for(r=t.size();r>=0 && s[r+1]==t[r];r--);

	cout<<(l>r ? l-r:0)<<endl;
	for(int i=r+1;i<=l;++i){
		cout<<i+1<<" ";
	}
}