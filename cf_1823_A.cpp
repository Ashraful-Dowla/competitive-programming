//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1823/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define ll long long
#define ld long double
#define vi vector<int> 
#define vll vector<ll> 
#define vs vector<string>
#define vb vector<bool> 
#define pii pair<int,int>
#define pll pair<ll,ll>


#define pb push_back
#define all(c) (c).begin(),(c).end()

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"
#define prnt1(x) cout<<x<<endl
#define prnt2(x,y) cout<<x<<" "<<y<<endl

const int N=1e5+10;
const int MOD=1e9+7;

void solve(){
	int n,k;
	cin>>n>>k;

	vi ans;
	for(int i=0;i<n;++i){
		int k1 = i*(i-1);
		int k2 = (n-i)*(n-i-1);
		k1/=2,k2/=2;
		if(k1+k2==k){
			for(int j=0;j<i;++j){
				ans.pb(-1);
			}
			for(int j=0;j<n-i;++j){
				ans.pb(1);
			}
			break;
		}
	}

	if(ans.size()){
		prnt1("YES");
		vec_prnt(ans);
	}
	else prnt1("NO");
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}