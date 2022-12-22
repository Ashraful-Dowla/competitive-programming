/*
https://codeforces.com/contest/1520/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int t;
	cin>>t;
	while(t--) {
	   int n;
	   cin>>n;
	   map<int,int>mp;
	   for(int i=1;i<=n;++i){
	   	 int x;
	   	 cin>>x;
	   	 mp[x-i]++;
	   }

	   ll sum=0;
	   for(auto it=mp.begin();it!=mp.end();++it){
	      int val = it->second;
	   	  ll nth_sum = 1LL*val*(val-1);
	   	  nth_sum/=2;
	   	  sum+=nth_sum;
	   }
	   cout<<sum<<endl;
	}
}