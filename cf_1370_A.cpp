/*
https://codeforces.com/contest/1370/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int mx_gcd[N];
vector<int>divisors[N];

void precompute(){
	for(int i=2;i<N;++i){
		for(int j=i;j<N;j+=i){
			if(divisors[j].size()==0){
				divisors[j].push_back(1);
			}
			divisors[j].push_back(i);
		}
	}

	int mx=1;
	for(int i=2;i<N;++i){
		int sz = divisors[i].size();
		mx = max(mx,divisors[i][sz-2]);
	    mx_gcd[i]=mx;
	}	
}

int main(){
	int t;
	scanf("%d",&t);
	precompute();

	while(t--) {
	    int n;
	    scanf("%d",&n);
	    printf("%d\n",mx_gcd[n]);
	}
}