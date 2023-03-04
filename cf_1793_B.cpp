/*
https://codeforces.com/contest/1793/problem/B
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
	int x,y;
	cin>>x>>y;

	vector<int> vec;

	for(int i=x;i>=y;--i){
		vec.push_back(i);
	}

	for(int i=y+1;i<x;++i){
		vec.push_back(i);
	}

	cout<<vec.size()<<endl;
	vec_prnt(vec);
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}