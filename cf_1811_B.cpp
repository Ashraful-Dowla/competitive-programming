//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1811/problem/B
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

	int n,x1,x2,y1,y2;
	cin>>n>>x1>>y1>>x2>>y2;

	int st = min({x1,y1, n-x1+1, n-y1+1});
	int nd = min({x2,y2, n-x2+1, n-y2+1});

	prnt1(abs(st-nd));
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}