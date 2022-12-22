/*
https://codeforces.com/problemset/problem/1497/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	   int n;
	   cin>>n;
	   int hsh[105];
	   memset(hsh,0,sizeof(hsh));

	   set<int>s;
	   for(int i=0;i<n;++i){
	   	 int x;
	   	 cin>>x;
	   	 s.insert(x);
	   	 hsh[x]++;
	   }

	   for(auto it=s.begin();it!=s.end();++it){
	   	  cout<<*it<<" ";
	   }

	   for(auto it=s.begin();it!=s.end();++it){
	   	 int val = *it;
	   	 for(int i=1;i<hsh[val];++i){
	   	 	cout<<val<<" ";
	   	 }
	   }
	   cout<<endl;
	}
}