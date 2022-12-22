/*
https://codeforces.com/problemset/problem/755/A
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
bool isPrime[N];

void prime(){
	memset(isPrime,true,sizeof(isPrime));

	isPrime[1]=false;
	for(int i=2;i<N;++i){
		if(isPrime[i]){
			for(int j=2*i;j<N;j+=i){
				isPrime[j]=false;
			}
		}
	}
}

int main(){
	int n;
	cin>>n;

	prime();

	for(int i=1;;++i){
		if(!isPrime[n*i+1]){
			cout<<i<<endl;
			break;
		}
	}

}