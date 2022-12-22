/*
https://codeforces.com/problemset/problem/1673/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	   string s;
	   cin>>s;

	   if(s.size()==1) cout<<"Bob "<<(s[0]-'a'+1)<<endl;
	   else {
	   	  cout<<"Alice ";
	   	  int sum=0,n=s.size();
	   	  for(int i=0;i<n;++i){
	   	  	sum+=(s[i]-'a'+1);
	   	  }

	   	  if(s.size()%2==0) cout<<sum<<endl;
	   	  else {
	   	  	 int l = (s[0]-'a'+1);
	   	  	 int r = (s[n-1]-'a'+1);
	   	  	 int x = sum-l;
	   	  	 int y = sum-r;

	   	  	 int ans = max(x-l,y-r);
	   	  	 cout<<ans<<endl;
	   	  }
	   }
	}
}