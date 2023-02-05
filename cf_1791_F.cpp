/*
https://codeforces.com/contest/1791/problem/F
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

const int N=2e5+10;
const int MOD=1e9+7;
int tree[N],n;
vector<int> digit_sum[N];

void add(int k,int x){
	while(k<=n){
		tree[k]+=x;
		k+=(k&-k);
	}
}

int sum(int k){
	int sum=0;
	while(k>=1){
		sum+=tree[k];
		k-=(k&-k);
	}
	return sum;
}

int calc_digit_sum(int num){
	int sum=0;
	while(num){
		sum+=(num%10);
		num/=10;
	}
	return sum;
}

void clr(){
	memset(tree,0,sizeof(tree));
	for(int i=1;i<=n;++i){
		digit_sum[i].clear();
	}
}

void solve(){
	int q;
	cin>>n>>q;

	int arr[n+2];
	for(int i=1;i<=n;++i){
		cin>>arr[i];

		while(arr[i]>=10){
			digit_sum[i].push_back(arr[i]);
			arr[i] = calc_digit_sum(arr[i]);
		}
		digit_sum[i].push_back(arr[i]);
	}

	while(q--){
		int tt,l,r,idx;
		cin>>tt;
		if(tt==1) {
			cin>>l>>r;
			add(l,1);
			add(r+1,-1);
		}
		else {
			cin>>idx;
			int i=sum(idx);
			int sz = digit_sum[idx].size();
			if(i>=sz) cout<<digit_sum[idx][sz-1]<<endl;
			else cout<<digit_sum[idx][i]<<endl;
		}
	}

	clr();
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}