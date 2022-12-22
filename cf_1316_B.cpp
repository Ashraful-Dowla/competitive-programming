/*
https://codeforces.com/contest/1316/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

string s;
int n;
string generate(int k){
	string pf = s.substr(k-1,n-k+1);
	string sf = s.substr(0,k-1);

	if(n%2==k%2) reverse(sf.begin(),sf.end());

	return pf+sf;
}


int main(){
	int t;
	cin>>t;
	while(t--) {
	 	cin>>n;
	 	cin>>s;

	 	string ans=generate(1);
	 	int k=1;
	 	for(int i=2;i<=n;++i){
	 		string str=generate(i);
	 		if(ans>str) {
	 			ans=str;
	 			k=i;
	 		}
	 	}

	 	cout<<ans<<endl;
	 	cout<<k<<endl;
	}
}