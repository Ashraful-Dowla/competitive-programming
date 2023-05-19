//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1829/problem/E
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

const int N=1e3+10;
const int MOD=1e9+7;

int n, m, arr[N][N], ct;
bool visited[N][N];

vector<pii> directions = {
	{1,0},
	{-1,0},
	{0,1},
	{0,-1}
};

bool isValid(int x,int y){
	return x>=0 && x<n && y>=0 && y<m;
}

void dfs(int i,int j){
	visited[i][j]=true;
	ct+=arr[i][j];

	for(auto d: directions){
		int x = i + d.first;
		int y = j + d.second;

		if(!isValid(x,y) || arr[x][y]==0 ||  visited[x][y]) continue;

		dfs(x,y);
	}
}


void clr(){
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			visited[i][j]=false;
		}
	}
}

void solve(){
	cin>>n>>m;

	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>arr[i][j];
		}
	}

	int ans=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			
			if(visited[i][j] || arr[i][j]==0) continue;
			
			ct=0;
			dfs(i,j);
			ans = max(ans, ct);
		}
	}

	prnt1(ans);
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