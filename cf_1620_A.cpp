/*
https://codeforces.com/problemset/problem/1620/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    string s;
	    cin>>s;
	    int cnt=0;
	    for(int i=0;i<s.size();++i){
	    	if(s[i]=='N') cnt++;
	    }
	    cout<<(cnt!=1 ? "YES": "NO")<<endl;
	}
}