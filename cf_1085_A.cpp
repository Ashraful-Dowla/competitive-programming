/*
https://codeforces.com/problemset/problem/1085/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	vector<char>vec(s.size());

	int sz = s.size();
	int l = sz%2==0 ? sz-2: sz-1;
	int i=0;
	
	while(l>=0) {
	    vec[l]=s[i];
	    l-=2;
	    ++i;
	}

	int r=1;
	while(i<sz){
		vec[r]=s[i];
		r+=2;
		++i;
	}

	for(int i=0;i<s.size();++i){
		cout<<vec[i];
	}
	cout<<endl;
}