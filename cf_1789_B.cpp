/*
https://codeforces.com/contest/1789/problem/B
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

	string s;
	cin>>s;

	int lo=0,hi=n-1;

	vector<int> diff,same;
	while(lo<=hi){
		if(diff.size()==0 && s[lo]!=s[hi]){
			diff.push_back(lo);
		}
		else if(diff.size()>0){
			if(s[lo]==s[hi]) same.push_back(lo);
			else diff.push_back(lo);

			if(same.size()>0 && diff.back()>same.back()){
				cout<<"NO"<<endl;
				return ;
			}
		}

		lo++,hi--;
	}

	cout<<"YES"<<endl;
	return ;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}