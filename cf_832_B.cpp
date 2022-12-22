/*
https://codeforces.com/contest/832/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

bool hsh[30];

string newPattern(string p,int d){
	string pat="";
	for(int i=0;i<p.size();++i){
		if(p[i]=='*'){
			for(int j=0;j<d;++j){
				pat.push_back(p[i]);
			}
		}
		else pat.push_back(p[i]);
	}

	return pat;
}

bool calc(string p,string t){
	int d = t.size()-p.size();
	if(d<-1) return false;

	p = newPattern(p,d+1);

	if(p.size()!=t.size()) return false;

	for(int i=0;i<p.size();++i){
		if(p[i]=='?') {
			if(!hsh[t[i]-'a']) return false;
		}
		else if(p[i]=='*') {
			if(hsh[t[i]-'a']) return false;
		}
		else {
			if(p[i]!=t[i]) return false;
		}
	}

	return true;
}

int main(){
	string gd,p;
	cin>>gd;
	cin>>p;

	for(int i=0;i<gd.size();++i){
		hsh[gd[i]-'a']=true;
	}

	int q;
	cin>>q;
	while(q--) {
	   string t;
	   cin>>t;
	   cout<<(calc(p,t)? "YES":"NO")<<endl;
	}

}