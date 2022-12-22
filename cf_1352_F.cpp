/*
https://codeforces.com/contest/1352/problem/F
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int n0,n1,n2;
	    cin>>n0>>n1>>n2;
	    string s;

	    if(n0>0 || n1>0) {
	    	s.push_back('0');
	    }

	    for(int i=0;i<n0;++i) {
	    	s.push_back('0');
	    }

	   	if(n2>0){
	   		s.push_back('1');
	   		s.push_back('1');
	   		n2--;
	   		if(n1>0) n1--;
	   	}

	   	for(int i=0;i<n2;++i){
	   		s.push_back('1');
	   	}

	   	for(int i=0;i<n1;++i){
	   		if(s.back()=='1') s.push_back('0');
	   		else  s.push_back('1');
	   	}

	   	cout<<s<<endl;
	}
}