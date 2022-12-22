/*
https://www.hackerearth.com/problem/algorithm/monks-birthday-party/?fbclid=IwAR3COuGp9LqoHKWOnfS-duVdKrF0Vx5shbCbGeiWqSgkdoA2z9926vNy5Ew
*/
#include <bits/stdc++.h>
using namespace std;

void prntSet(set<string> &s){
	for(string val: s){
		cout<<val<<endl;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		set<string>s;
		for(int i=0;i<n;i++){
			string str;
			cin>>str;
			s.insert(str);
		}
		prntSet(s);
	}
}