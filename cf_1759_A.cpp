/*
https://codeforces.com/contest/1759/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--) {
	    string s;
	    cin>>s;

	    int cnt[200];
	    memset(cnt,0,sizeof(cnt));
	    for(int i=0;i<s.size();++i){
	    	cnt[tolower(s[i])-'a']++;
	    }

	    int mx = 0;
	    mx = max(mx,cnt['y'-'a']);
	    mx = max(mx,cnt['e'-'a']);
	    mx = max(mx,cnt['s'-'a']);

	    string ans="";
	    for(int i=0;i<mx+2;++i){
	    	ans+="Yes";
	    }
	    
	    size_t found = ans.find(s);
	    if(found!=string::npos) cout<<"YES"<<endl;
	    else cout<<"NO"<<endl;
	}
}