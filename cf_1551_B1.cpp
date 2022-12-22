/*
https://codeforces.com/problemset/problem/1551/B1
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--) {
	 	string s;
	 	cin>>s;

	 	bool red[30],green[30];
	 	memset(red,false,sizeof(red));
	 	memset(green,false,sizeof(green));

	 	red[s[0]-'a']=true;
	 	int g=0,r=1;
	 	for(int i=1;i<s.size();++i){
	 		if(!red[s[i]-'a']){
	 			r++;
	 			red[s[i]-'a']=true;
	 		}
	 		else if(!green[s[i]-'a']){
	 			g++;
	 			green[s[i]-'a']=true;
	 		}
	 	}

	 	cout<<(g+r)/2<<endl;
	}
}