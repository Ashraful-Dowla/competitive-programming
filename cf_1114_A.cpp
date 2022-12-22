/*
https://codeforces.com/problemset/problem/1114/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int x,y,z;
	cin>>x>>y>>z;
	int a,b,c;
	cin>>a>>b>>c;

	if(a<x) {
		cout<<"NO"<<endl;
		return 0;
	}

	int res_a = a-x;
	if(res_a+b<y){
		cout<<"NO"<<endl;
		return 0;
	}

	int res_b = res_a+b-y;

	if(res_b+c<z){
		cout<<"NO"<<endl;
		return 0;
	}

	cout<<"YES"<<endl;
}