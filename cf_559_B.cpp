/*
https://codeforces.com/problemset/problem/559/B
*/
#include <bits/stdc++.h>
using namespace std;

string generate(string s){
	if(s.size()%2) return s;
	int len = s.size()/2;
	string s1 = generate(s.substr(0,len));
	string s2 = generate(s.substr(len,len));
	return min(s1+s2,s2+s1);
}

int main(){
	string a,b;
	cin>>a>>b;
	cout<<(generate(a)==generate(b) ? "YES": "NO")<<endl;
}