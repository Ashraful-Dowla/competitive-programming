/*
https://codeforces.com/contest/1789/problem/A
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

	vector<int> vec;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		vec.push_back(x);
	}

	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			int gcd = __gcd(vec[i],vec[j]);
			if(gcd<=2){
				cout<<"YES"<<endl;
				return ;
			}
		}
	}

	cout<<"NO"<<endl;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}