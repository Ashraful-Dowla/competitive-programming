/*
https://codeforces.com/contest/1798/problem/D
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define vi vector<int> 

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"

const int N=1e5+10;
const int MOD=1e9+7;

bool cmp(int a,int b){
	return a>b;
}

void solve(){
	int n;
	cin>>n;

	vi pos,neg;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		if(x>=0) pos.push_back(x);
		else neg.push_back(x);
	}

	sort(pos.begin(),pos.end(), cmp);
	sort(neg.begin(),neg.end());

	if(pos.size()==0 || neg.size()==0){
		cout<<"No"<<endl;
		return ;
	}

	ll res = pos[pos.size()-1] - neg[0];

	int i=0,j=0;
	ll sum=0;

	vi ans;
	while(i<pos.size() && j<neg.size()){
		if(sum+pos[i]<res){
			sum+=pos[i];
			ans.push_back(pos[i]);
			++i;
		}
		else {
			sum+=neg[j];
			ans.push_back(neg[j]);
			++j;
		}
	}

	while(i<pos.size() && sum+pos[i]<res){
		sum+=pos[i];
		ans.push_back(pos[i]);
		++i;
	}

	while(j<neg.size() && sum+neg[j]<res){
		sum+=neg[j];
		ans.push_back(neg[j]);
		++j;
	}

	if(ans.size()==n) {
	   cout<<"Yes"<<endl;
	   vec_prnt(ans);
	}
	else cout<<"No"<<endl;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}