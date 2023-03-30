/*
https://codeforces.com/contest/1809/problem/C
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
	int n,k;
	cin>>n>>k;

	if(k==0){
		for(int i=0;i<n;++i){
			cout<<-2<<" ";
		}
		cout<<endl;
		return ;
	}

	int nn;
	for(int i=1;i<=30;++i){
		int val = i*(i+1)/2;
		if(val<=k) nn=i;
		else break;
	}

	vector<int> ans;

	int sum=nn*(nn+1)/2;
	int x=k-sum;

	for(int i=0;i<n;++i){
		if(i<nn) ans.push_back(2);
		else if(i==nn){
			if(x==0) ans.push_back(-1000);
			else {
				int val = (nn-x+1)*2-1;
				ans.push_back(-val);
			}
		}
		else ans.push_back(-1000);
	}

	vec_prnt(ans);
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}