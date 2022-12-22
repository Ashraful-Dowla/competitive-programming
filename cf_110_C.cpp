/*
https://codeforces.com/problemset/problem/110/C
*/
#include <bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin>>n;

	string s="";
	int sv=0;
	while(n>0) {
	   	if(n%7==0){
	   		sv+=(n/7);
	   		n=0;
	   	}
	   	else {
	   		n-=4;
	   		s.push_back('4');
	   	}
	}

	for(int i=0;i<sv;++i){
		s.push_back('7');
	}

	cout<<(n==0 ? s : "-1")<<endl;
}