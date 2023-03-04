/*
https://codeforces.com/contest/1791/problem/G1
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

const int N=1e5+10;
const int MOD=1e9+7;

void solve(){
	int n;
	ll c;
	cin>>n>>c;
	vector<ll> vec(n+2);

	for(int i=1;i<=n;++i){
		cin>>vec[i];
		vec[i]+=i;
	}

	sort(vec.begin()+1,vec.begin()+n+1);

	int i=1;
	while(i<=n && c>=vec[i]){
		c-=vec[i];
		i++;
	}

	cout<<(i-1)<<endl;

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}