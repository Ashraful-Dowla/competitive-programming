/*
https://codeforces.com/problemset/problem/1562/B
*/
#include <bits/stdc++.h>
using namespace std;

bool isPrime[100];

bool prime(){
	memset(isPrime,true,sizeof(isPrime));
	for(int i=2;i<100;++i){
		if(isPrime[i]){
			for(int j=2*i;j<100;j+=i){
				isPrime[j]=false;
			}
		}
	}
}

void solve(string s){
	for(int i=0;i<s.size();++i){
		if(s[i]=='1' || s[i]=='4' || s[i]=='6' || s[i]=='8' || s[i]=='9'){
			cout<<1<<endl;
			cout<<s[i]<<endl;
			return ;
		}
	}

	for(int i=0;i<s.size();++i){
		for(int j=i+1;j<s.size();++j){
			int val = (s[i]-'0')*10 + (s[j]-'0');
			if(!isPrime[val]){
				cout<<2<<endl;
				cout<<val<<endl;
				return ;
			}
		}
	}
}

int main(){
	int t;
	cin>>t;

	prime();

	while(t--) {
		int n;
		cin>>n;
	    string s;
	    cin>>s;
	    solve(s);
	}
}