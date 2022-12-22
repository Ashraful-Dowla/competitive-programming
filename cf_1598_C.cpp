/*
https://codeforces.com/contest/1598/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	   int n;
	   cin>>n;

	   double arr[n+2],sum=0; 
	   map<double,int>taken;
	   for(int i=0;i<n;++i){
	   	  cin>>arr[i];
	   	  sum+=arr[i];
	   	  taken[arr[i]]++;
	   }

	   double k=sum/(n*1.0);
	   double k2=k*2;

	   long long cnt=0;
	   for(int i=0;i<n;++i){
	   	  double val = arr[i];
	   	  if(taken[k2-val]){
	   	  	  taken[val]--;
	   	  	  cnt+=taken[k2-val];
	   	  }
	   }
	   cout<<cnt<<endl;
	}
}