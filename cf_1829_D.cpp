//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1829/problem/D
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
	
int n,m;
bool calc(int x){

	if(n==x) return true;

	bool isPossible = false;
	if(x<n){
		if(x%2==0) isPossible|=calc((x*3)/2);
		isPossible|=calc(x*3);
	}

	return isPossible;
}

void solve(){
	cin>>n>>m;
	bool chk = calc(m);

	cout<<(chk ? "YES": "NO")<<endl;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}