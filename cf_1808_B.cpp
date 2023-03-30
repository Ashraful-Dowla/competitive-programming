//Author: Ashraful Dowla

/*
https://codeforces.com/contest/1808/problem/B
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
#define prnt1(x) cout<<x<<endl
#define prnt2(x,y) cout<<x<<" "<<y<<endl

const int N=1e5+10;
const int MOD=1e9+7;

ll calculate(vi &vec){
	
	sort(all(vec));

	int n=vec.size();
	ll sum=0;
	for(int i=0;i<n;++i){
		sum +=(i*1LL*vec[i] -(n-i-1)*1LL*vec[i]);
	}

	return sum;
}

void solve(){
	
	int n,m;
	cin>>n>>m;

	vector<vi> vec(m);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			int x;
			cin>>x;
			vec[j].push_back(x);
		}
	}

	ll sum=0;

	for(int i=0;i<m;++i){
		sum+=calculate(vec[i]);
	}

	prnt1(sum);
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}