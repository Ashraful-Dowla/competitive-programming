/*
https://codeforces.com/problemset/problem/1466/D
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+10;

ll weight[N],ans,degree[N];

bool cmp(ll a,ll b){
	return a>b;
}

int main(){
	int t;
	// cin>>t;
	scanf("%d",&t);


	while(t--) {
	   int n;
	   // cin>>n;
	   scanf("%d",&n);


	   ans=0;	   
	   vector<ll> vec;

	   for(int i=1;i<=n;++i){
	   	    // cin>>weight[i];
	   	    scanf("%lld",&weight[i]);
	   	    degree[i]=0;
	   		ans+=weight[i];
	   }

	   for(int i=0;i<n-1;++i){
	   		int u,v;
	   		// cin>>u>>v;
	   	    scanf("%d %d",&u,&v);
	   		degree[u]++;
	   		degree[v]++;
	   }

	   for(int i=1;i<=n;++i){
	   	  for(int j=1;j<degree[i];++j){
	   	  	  vec.push_back(weight[i]);
	   	  }
	   }

	   sort(vec.begin(),vec.end(),cmp);

	   for(auto &val:vec){
	   	  // cout<<ans<<" ";
	   	  printf("%lld ",ans);
	   	  ans+=val;
	   }
	   printf("%lld\n",ans);
	}
}