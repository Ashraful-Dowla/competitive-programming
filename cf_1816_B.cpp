//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1816/problem/B
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
	int n;
	cin>>n;

	int a[2][n+2];

	a[0][1]=2*n-1;
	a[1][n]=2*n;

	for(int i=2;i<=n;++i){
		if(i%2==0){
			a[0][i]=i;
			a[1][i-1]=i-1;
		}
		else {
			a[0][i]=n+i-1;
			a[1][i-1]=n+i-2;
		}
	}

	for(int i=0;i<2;++i){
		for(int j=1;j<=n;++j){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}