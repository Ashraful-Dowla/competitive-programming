//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1816/problem/A
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
	ll x,y;
	cin>>x>>y;

	if(x==1 && y==1){
		prnt1(1);
	}
	else {
		prnt1(2);
		prnt2(1,y-1);
	}

	prnt2(x,y);

}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}