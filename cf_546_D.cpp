/*
https://codeforces.com/problemset/problem/546/D
*/
#include <bits/stdc++.h>
using namespace std;

const int N=5e6+10;
int hp[N],cnt[N];
bool isPrime[N];

void precompute(){
	memset(isPrime,true,sizeof(isPrime));

	for(int i=2;i<N;++i){
		if(isPrime[i]){
			hp[i]=i;
			for(int j=2*i;j<N;j+=i){
				isPrime[j]=false;
				hp[j]=i;
			}
		}
	}


	for(int i=2;i<N;++i){
		int val=i,ct=0;
		while(val>1){
			int pf_factor = hp[val];
			while(val%pf_factor==0) {
			    val/=pf_factor;
			    ct++;
			}
		}
		cnt[i]=cnt[i-1]+ct;
	}
}

int main(){
	precompute();

	int t;
	scanf("%d",&t);
	
	while(t--){
		int a,b;
		scanf("%d%d",&a,&b);

		printf("%d\n",cnt[a]-cnt[b]);
	}
}