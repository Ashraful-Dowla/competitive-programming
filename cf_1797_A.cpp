//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1797/problem/A
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

vector<pii> directions = {
	{0,-1},
	{0,1},
	{-1,0},
	{1,0}
};

bool isValid(int x,int y, int n,int m){
	return x>=1 && x<=n && y>=1 && y<=m;
}

int calcBlock(int x, int y,int n, int m){

	int cnt=0;
	for(auto coord: directions){
		int _x = x + coord.first;
		int _y = y + coord.second;

		if(isValid(_x,_y,n,m)) cnt++;
	}

	return cnt;
}

void solve(){
	int n,m;
	cin>>n>>m;

	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;

	int ans = 4;
	ans = min(ans, min(n,m));

	ans = min(ans , calcBlock(x1,y1,n,m));
	ans = min(ans , calcBlock(x2,y2,n,m));

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