/*
https://codeforces.com/problemset/problem/1175/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;

		long long cnt=0;
		while(n){
			if(n%k==0){
				cnt+=1;
				n/=k;
			}
			else {
				long long md = n%k;
				cnt+=md;
				n-=md;
			}
		}
		cout<<cnt<<endl;
	}
}