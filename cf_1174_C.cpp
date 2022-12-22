/*
https://codeforces.com/problemset/problem/1174/C
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
bool isPrime[N];
int cnt[N];

void precompute(int n){
	int k=1;
	for(int i=2;i<=n;++i){
		if(isPrime[i]){
			cnt[i]=k++;
			for(int j=2*i;j<=n;j+=i){
				isPrime[j]=false;
				cnt[j]=cnt[i];
			}
		}
	}
}

int main(){
	int n;
	cin>>n;

	memset(isPrime,true,sizeof(isPrime));
	precompute(n);
	for(int i=2;i<=n;++i){
		cout<<cnt[i]<<" ";
	}
	cout<<endl;
}