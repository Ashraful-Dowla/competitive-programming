//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1797/problem/B
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

const int N=1e3+10;
const int MOD=1e9+7;

int arr[N][N];

void solve(){
	int n,k;
	cin>>n>>k;

	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>arr[i][j];
		}
	}

	if(n==1){
		prnt1("Yes");
		return ;
	}

	int lo=0, hi=n-1, ct=0;
	while(lo<hi){
		for(int i=0;i<n;++i){
			if(arr[lo][i]==arr[hi][n-i-1]) continue;
			ct++;
		}
		lo++,hi--;
	}

	if(n&1){
		lo=0, hi=n-1;
		int md = (n-1)/2;
		while(lo<hi){
			if(arr[md][lo]!=arr[md][hi]) ct++;
			lo++,hi--;
		}
	}


	k-=ct;

	if(k<0) prnt1("No");
	else if(n%2==1) prnt1("Yes");
	else if(k%2==1) prnt1("No");
	else prnt1("Yes");

}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}