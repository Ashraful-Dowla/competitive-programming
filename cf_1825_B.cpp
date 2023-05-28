//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1825/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define ll long long
#define ld long double
#define vi vector<int> 
#define vs vector<string>
#define vb vector<bool> 
#define pii pair<int,int>
#define pll pair<ll,ll>


#define pb push_back
#define all(c) (c).begin(),(c).end()

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"
#define prnt1(x) cout<<x<<endl;
#define prnt2(x,y) cout<<x<<" "<<y<<endl;

const int N=1e5+10;
const int MOD=1e9+7;

void solve(){
	int n,m;
	cin>>n>>m;

	vi vec(n*m);
	for(int i=0;i<n*m;++i){
		cin>>vec[i];
	}

	sort(all(vec));
	int f_mx = vec[n*m-1], s_mx = vec[n*m-2], mn = vec[0], s_mn=vec[1];

	int ans = (f_mx - mn) * (n-1) * m + (s_mx - mn) * (m-1);
	ans = max(ans, (f_mx - mn) * (m-1) * n + (s_mx - mn) * (n-1));

	ans = max(ans, (f_mx - mn) * (n-1)*m + (f_mx - s_mn) * (m-1));
	ans = max(ans, (f_mx - mn) * (m-1)*n + (f_mx - s_mn) * (n-1));

	prnt1(ans);
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}