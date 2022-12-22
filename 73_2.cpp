/*
https://codeforces.com/contest/776/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int>isPrime(N,true);
vector<int>colors(N,0);

void primeList(int n){
	for(int i=2;i<n+2;++i){
		if(isPrime[i]){
			colors[i]=1;
			for(int j=2*i;j<N;j+=i){
				isPrime[j]=false;
				colors[j]=2;
			}
		}
	}
}

int main(){
	int n;
	cin>>n;

	primeList(n);
	int mx = *max_element(colors.begin()+2,colors.begin()+n+2);
	cout<<mx<<endl;
	for(int i=2;i<n+2;++i){
		cout<<colors[i]<<" ";
	}
	cout<<endl;
}