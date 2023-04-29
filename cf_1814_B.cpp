//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1814/problem/B
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

int calc(int a, int b){
	
	int ans=INT_MAX;
	for(int i=1;i<=1e6;++i){
		double r = i - 1 + ceil(1.0*a/i) + ceil(1.0*b/i);
		ans = min(ans, (int)r);
	}
	
	return ans;
}

void solve(){
	int a,b;
	cin>>a>>b;
	prnt1(calc(a,b));
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}