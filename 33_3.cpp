/*
https://www.hackerrank.com/challenges/cpp-maps/problem
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	map<string,int>m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		string s;
		int num;
		if(x==1){
			cin>>s>>num;
			m[s]+=num;
		}
		else {
			cin>>s;
			if(x==2) m[s]=0;
			else cout<<m[s]<<endl;
		}
	}
}