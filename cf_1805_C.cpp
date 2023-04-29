//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1805/problem/C
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

struct node{
	ll a,b,c;
};

void solve(){
	int n,m;
	cin>>n>>m;

	vll line(n);
	for(int i=0;i<n;++i){
		cin>>line[i];
	}

	vector<node> parabola(m);
	for(int i=0;i<m;++i){
		cin>>parabola[i].a>>parabola[i].b>>parabola[i].c;
	}

	sort(line.begin(),line.end());

	for(int i=0;i<m;++i){

		ll a=parabola[i].a;
		ll b=parabola[i].b;
		ll c=parabola[i].c;

		int idx = lower_bound(all(line),b) - line.begin();
		
		if(idx>0 && (b-line[idx-1])*(b-line[idx-1]) < 4*a*c){
			prnt1("Yes");
			prnt1(line[idx-1]);
			continue;
		}

		if(idx<n && (b-line[idx])*(b-line[idx]) < 4*a*c){
			prnt1("Yes");
			prnt1(line[idx]);
			continue;
		}

		prnt1("No");
	}

	// prnt1("---");
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}