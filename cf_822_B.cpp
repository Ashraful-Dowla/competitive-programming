/*
https://codeforces.com/contest/822/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	string s,t;
	cin>>s;
	cin>>t;

	vector<int> ans,ans2;

	for(int i=0;i<n;++i){
		ans.push_back(i);
	}

	for(int i=0;i<m-n+1;++i){
		for(int j=0;j<n;++j){
			if(s[j]!=t[j+i]){
				ans2.push_back(j);
			}
		}

		if(ans2.size()<ans.size()) ans=ans2;
		ans2.clear();
	}

	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();++i){
		cout<<ans[i]+1<<" ";
	}
	cout<<endl;
}