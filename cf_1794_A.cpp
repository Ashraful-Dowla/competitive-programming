/*
https://codeforces.com/contest/1794/problem/A
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

	vector<string> vec;

	for(int i=0;i<2*n-2;++i){
		string s;
		cin>>s;

		if(s.size()==n-1) vec.push_back(s);
	}

	reverse(vec[1].begin(),vec[1].end());

	cout<<(vec[1]==vec[0] ? "YES" : "NO")<<endl;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}