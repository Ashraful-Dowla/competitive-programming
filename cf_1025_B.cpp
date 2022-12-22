/*
https://codeforces.com/contest/1025/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> s;
unordered_map<int,bool>taken;

void prime_fact(int n){
	for(int i=2;i*i<=n;++i){
		if(n%i==0){
			if(!taken[i]){
				s.push_back(i);
				taken[i]=true;
			}
			if(!taken[n/i]){
				s.push_back(n/i);
				taken[n/i]=true;
			}
		}
	}

	s.push_back(n);
	taken[n]=true;
}

int main(){
	int n;
	// cin>>n;
	scanf("%d",&n);

	int A[n],B[n];
	for(int i=0;i<n;++i){
		int a,b;
		// cin>>a>>b;
		scanf("%d %d",&A[i],&B[i]);
	}

	prime_fact(A[0]);
	prime_fact(B[0]);

	int ans=-1;
	for(auto val: s){
		int idx=1;
		while(idx<n &&(A[idx]%val==0 || B[idx]%val==0)){
			idx++;
		}

		if(idx==n) {
			ans=val;
			break;
		}
	}

	// cout<<ans<<endl;
	printf("%d\n",ans);
}