/*
https://codeforces.com/contest/1768/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;

	vector<int>p(n+2),q(n+2),a(n+2);
	vector<int>adj[n+2];

	for(int i=1;i<=n;++i){
		cin>>a[i];
		adj[a[i]].push_back(i);
	}

	stack<int> stk_a,stk_b;
	bool ok=true;

	for(int i=n;i>=1;--i){
		int sz = adj[i].size();

		if(sz==0){
			if(stk_a.empty() || stk_b.empty()){
				ok=false;
				break;
			}

			int pos = stk_a.top();
			stk_a.pop();
			p[pos] = i;

			pos = stk_b.top();
			stk_b.pop();
			q[pos]=i;
		}
		else if(sz==1){
			int pos = adj[i][0];
			p[pos]=q[pos]=i;
		}
		else if(sz==2){
			int pos1 = adj[i][0];
			int pos2 = adj[i][1];

			p[pos1] = i;
			q[pos2] = i;

			stk_a.push(pos2);
			stk_b.push(pos1);
		}
		else {
			ok=false;
			break;
		}
	}

	if(!ok) cout<<"NO"<<endl;
	else {
		cout<<"YES"<<endl;
		for(int i=1;i<=n;++i){
			cout<<p[i]<<" ";
		}
		cout<<endl;
		for(int i=1;i<=n;++i){
			cout<<q[i]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    solve();
	}
}