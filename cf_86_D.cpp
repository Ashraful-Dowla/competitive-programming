/*
https://codeforces.com/contest/86/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10,M=1e6+10;

struct Q
{
	int idx,l,r;	
};

typedef long long ll;

int rootN;
Q queries[N];
	
ll mp[M],curr_ans;

bool comp(Q q1, Q q2){
	if(q1.l/rootN == q2.l/rootN){
		return q1.r>q2.r;
	}
	return q1.l/rootN<q2.l/rootN;
}


ll calc(ll val, ll x){
	curr_ans-=val*mp[val]*mp[val];
	mp[val]+=x;
	curr_ans+=val*mp[val]*mp[val];
}

int main(){
	int n,m;
	// cin>>n>>m;
	scanf("%d %d",&n,&m);

	ll arr[n];
	for(int i=0;i<n;++i){
		// cin>>arr[i];
		scanf("%lld",arr+i);
	}

	for(int i=0;i<m;++i){
		int l,r;
		// cin>>l>>r;
		scanf("%d %d",&l,&r);
		queries[i].l=l;
		queries[i].r=r;
		queries[i].idx=i;
	}

	rootN=sqrtl(n);
	sort(queries,queries+m,comp);

	int curr_l=0,curr_r=-1,l,r;
	ll ans[m];

	for(int i=0;i<m;++i){
		l=queries[i].l,r=queries[i].r;
		l--,r--;

		while(curr_r<r){
			curr_r++;
			calc(arr[curr_r],1);
		}

		while(curr_l>l){
			curr_l--;
			calc(arr[curr_l],1);
		}

		while(curr_l<l){
			calc(arr[curr_l],-1);
			curr_l++;
		}

		while(curr_r>r){
			calc(arr[curr_r],-1);
			curr_r--;
		}
		ans[queries[i].idx]=curr_ans;
	}

	for(int i=0;i<m;++i){
		// cout<<ans[i]<<endl;
		printf("%lld\n",ans[i]);
	}


}