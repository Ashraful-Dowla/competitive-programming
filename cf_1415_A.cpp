/*
https://codeforces.com/problemset/problem/1415/A
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pr;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    ll n,m,r,c,i=1,j=1,mx=0;
	    cin>>n>>m>>r>>c;
	    vector<pr>vec = {
			{1,1},
			{1,m},
			{n,1},
			{n,m}
		};
		for(int i=0;i<vec.size();++i){
			ll ith=vec[i].first;
			ll jth=vec[i].second;
			mx = max(mx,abs(r-ith)+abs(c-jth));
		}
		cout<<mx<<endl;
	}
}