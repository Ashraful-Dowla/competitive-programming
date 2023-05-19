//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1829/problem/C
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


void solve(){
	int n;
	cin>>n;

	vi vec[15];

	for(int i=0;i<n;++i){
		int x,y;
		cin>>x>>y;

		vec[y].pb(x);
	}

	sort(vec[11].begin(),vec[11].end());
	sort(vec[10].begin(),vec[10].end());
	sort(vec[1].begin(),vec[1].end());

	int ans1 = -1, ans2 = -1;

	if(vec[1].size() && vec[10].size()) ans1 = vec[1][0]+vec[10][0];

	if(vec[11].size()) ans2 =vec[11][0];

	if(ans1!=-1 && ans2!=-1) {
		prnt1(min(ans1,ans2));
	}
	else if(ans1!=-1) {
		prnt1(ans1);
	}
	else if(ans2!=-1){
		prnt1(ans2);
	}
	else prnt1(-1);
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}