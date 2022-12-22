/*
https://codeforces.com/problemset/problem/1582/C
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;

	  	int ans=INT_MAX;
	   	for(char ch='a';ch<='z';ch++){
	   		int l=0,r=n-1,cnt=0;
	   		while(l<=r){
	   			if(s[l]==s[r]){
	   				l++,r--;
	   			}
	   			else if(s[l]==ch){
	   				l++;
	   				cnt++;
	   			}
	   			else if(s[r]==ch){
	   				r--;
	   				cnt++;
	   			}
	   			else {
	   				cnt=INT_MAX;
	   				break;
	   			}
	   		}
	   		ans = min(ans,cnt);
	   	}

	   	if(ans==INT_MAX) cout<<-1<<endl;
	   	else cout<<ans<<endl;
	}
}