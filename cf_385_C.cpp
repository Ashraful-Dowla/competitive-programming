/*
https://codeforces.com/contest/385/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e7+1;
bool isPrime[N],taken[N];
int cnt[N],ct[N];

void precompute(){
	memset(isPrime,true,sizeof(isPrime));

	for(int i=2;i<N;++i){
		if(isPrime[i]){
			if(taken[i]) cnt[i]+=ct[i];
			for(int j=2*i;j<N;j+=i){
				isPrime[j]=false;
				if(taken[j]) cnt[i]+=ct[j];
			}
		}
	}

	for(int i=2;i<N;++i){
		cnt[i]+=cnt[i-1];
	}

}

int main(){
	int n;
	// cin>>n;
	scanf("%d",&n);

	for(int i=0;i<n;++i){
		int x;
		// cin>>x;
		scanf("%d",&x);

		taken[x]=true;
		ct[x]++;
	}

	precompute();
	int q;
	// cin>>q;
	scanf("%d",&q);

	while(q--) {
	   int l,r;
	   // cin>>l>>r;
	   scanf("%d %d",&l,&r);

	   if(r>=N) r=N-1;
	   if(l>=N) l=N;
	   printf("%d\n", cnt[r]-cnt[l-1]);
	}
}