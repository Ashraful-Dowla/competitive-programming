/*
https://codeforces.com/contest/1798/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define vi vector<int> 

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"

const int N=5e4+10;
const int MOD=1e9+7;

void solve(){
	int m;
	cin>>m;

	int a[N];
	vi lottery[m];

	for(int i=0;i<m;++i){
		int n;
		cin>>n;
		for(int j=0;j<n;++j){
			int x;
			cin>>x;
			a[x]=i;
			lottery[i].push_back(x);
		}
	}

	vi ans;
	for(int i=0;i<m;++i){
		for(int x: lottery[i]){
			if(a[x]==i){
				ans.push_back(x);
				break;
			}
		}
		if(ans.size()!=(i+1)){
			cout<<-1<<endl;
			return ;
		}
	}

	vec_prnt(ans);
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}