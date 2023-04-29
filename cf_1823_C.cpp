//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1823/problem/C
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

const int N=1e7+10;
const int MOD=1e9+7;

int cnt_primes[N];
vi primes;

void calc_prime(int n){
	for(int i=2;i*i<=n;++i){
		 while(n%i==0){
		 	if(cnt_primes[i]==0) primes.pb(i);
		 	cnt_primes[i]++;
		 	n/=i;
		 }
	}

	if(n>1) {
		if(cnt_primes[n]==0) primes.pb(n);
		cnt_primes[n]++;
	}
}

void clr(){
	for(auto &p: primes){
		cnt_primes[p]=0;
	}
	primes.clear();
}

void solve(){
	int n;
	cin>>n;

	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		calc_prime(x);
	}

	// vec_prnt(primes);

	int cnt=0, rem=0;
	for(auto &p: primes){
		cnt+=(cnt_primes[p]/2);
		rem+=(cnt_primes[p]%2);
	}

	cnt+=(rem/3);

	prnt1(cnt);
	clr();
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}