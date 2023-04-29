//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1811/problem/E
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

ll convert_base_to_9(ll n){

	ll res=0,p=1;
	while(n>0){
		res+=(p*(n%9));
		n/=9;
		p*=10;
	}

	return res;
}

ll compute(ll n, ll k){

	ll res=0, p=1;

	while(n>0){

		ll rem = n%10;

		if(rem>=k) res+=(p*(rem+1));
		else res+=p*rem;

		n/=10;
		p*=10;
	}

	return res;
}

void solve(){
	ll n;
	cin>>n;

	n = convert_base_to_9(n);

	prnt1(compute(n,4));
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}