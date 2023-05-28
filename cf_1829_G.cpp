//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1829/problem/G
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

const int N=1500;
const int MOD=1e9+7;

ll pf[N][N], arr[N][N];
map<int,pii> mp;

void precompute(){

	int num=1;
	for(int i=1;i<N;++i){
		int x=i;
		for(int j=1;x>0;++j,--x){
			arr[x][j]=(num*1LL*num);
			mp[num] = {x,j};
			num++;
		}
	}

	for(int i=1;i<N;++i){
		for(int j=1;j<N;++j){
			pf[i][j] = arr[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
		}
	}
}

void solve(){
	int n;
	cin>>n;

	int a=1, b=1, c=mp[n].first, d=mp[n].second;

	ll sum = pf[c][d] - pf[a-1][d] - pf[c][b-1] + pf[a-1][b-1];
	prnt1(sum);
}

int main(){
	Faster;	

	precompute();

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}