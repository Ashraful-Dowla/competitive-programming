/*
https://codeforces.com/contest/1795/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"

const int N=1e5+10;
const int MOD=1e9+7;

void solve(){
	int n;
	cin>>n;
	vector<ll> a(n+2),b(n+2);

	for(int i=1;i<=n;++i){
		cin>>a[i];
	}

	for(int i=1;i<=n;++i){
		cin>>b[i];
	}

	vector<ll> pf(n+3,0);
	for(int i=1;i<=n;++i){
		pf[i] = b[i] + pf[i-1];
	}

	vector<ll> cnt(n+5,0),left(n+5,0);

	for(int i=1;i<=n;++i){
		if(a[i]>=(pf[n]-pf[i-1])){
			cnt[i]++;
			cnt[n+1]--;
		}
		else {
			int idx=-1;
			int lo=i,hi=n;
			while(lo<=hi){
				int mid=(lo+hi)/2;
				if(a[i]>=(pf[mid]-pf[i-1])){
					lo=mid+1;
					idx=mid;
				}
				else hi=mid-1;
			}

			if(idx==-1) left[i]+=a[i];
			else {
				cnt[i]++;
				cnt[idx+1]--;
				left[idx+1]+=a[i]-(pf[idx]-pf[i-1]);
			}
		}
	}

	for(int i=1;i<=n;++i){
		cnt[i]+=cnt[i-1];
	}

	for(int i=1;i<=n;++i){
		cout<<left[i] + cnt[i]*b[i]<<" ";
	}
	cout<<endl;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}