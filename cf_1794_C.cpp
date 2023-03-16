/*
https://codeforces.com/contest/1794/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"

const int N=1e5+10;
const int MOD=1e9+7;

void solve(){
	int n;
	cin>>n;

	vector<int> vec(n+2);
	for(int i=1;i<=n;++i){
		cin>>vec[i];
	}

	vector<int> ans;
	for(int i=1;i<=n;++i){
		int lo=1,hi=i;

		while(lo<=hi){
			int mid= (hi+lo)/2;
			int len = (i-mid+1);

			if(vec[mid]>=len) hi=mid-1;
			else lo=mid+1;
		}

		ans.push_back(i-lo+1);
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