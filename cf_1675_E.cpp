/*
https://codeforces.com/problemset/problem/1675/E
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		string str;
		cin>>str;

		map<char, bool>mp;
		for(int i=0;i<n;++i){
			while(str[i]>'a'){
				if(mp[str[i]]) str[i]--;
				else if(k) {
					mp[str[i]]=true;
					str[i]--;
					k--;
				}
				else break;
			}
		}
		cout<<str<<endl;
	}
}