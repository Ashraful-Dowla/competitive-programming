/*
https://codeforces.com/contest/1005/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;

	int ct=0,a=0,b=0;
	
	for(int i=0;i<s.size();++i){
		int vl=s[i]-'0';

		if(vl%3==0 || (vl+a)%3==0 || (vl+a+b)%3==0){
			ct++;
			a=b=0;
		}
		else a=b,b=vl;
	}

	cout<<ct<<endl;
}