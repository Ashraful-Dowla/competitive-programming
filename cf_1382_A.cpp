/*
https://codeforces.com/problemset/problem/1382/A
*/
#include <bits/stdc++.h>
using namespace std;

int a[1005],b[1005];

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;++i) cin>>a[i];
		for(int i=0;i<m;++i) cin>>b[i];

		set<int>st;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(a[i]==b[j]){
					st.insert(a[i]);
				}
			}
		}
		if(st.size()){
			cout<<"YES"<<endl;
			cout<<"1 "<<*(st.begin())<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}