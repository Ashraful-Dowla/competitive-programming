/*
https://codeforces.com/problemset/problem/1185/B
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<char,int> pr;

vector<pr> calculate(string s){
	vector<pr> res;
	 for(int i=0;i<s.size();++i){
	    if(res.empty() ||  res.back().first!=s[i]){
	    	res.push_back({s[i],1});
	    }
	    else res.back().second++;
	}

	return res;
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    string s,t;
	    cin>>s;
	    cin>>t;	

	    vector<pr> pf_s = calculate(s);
	    vector<pr> pf_t = calculate(t);
	  
	    if(pf_s.size()!=pf_t.size()) cout<<"NO"<<endl;
	    else {
	    	int sz=pf_s.size();
	    	bool chk=true;
	    	for(int i=0;i<sz;++i){
	    		if(pf_s[i].first==pf_t[i].first && pf_s[i].second<=pf_t[i].second){
	    			continue;
	    		}
	    		chk=false;
	    		break;
	    	}

	    	cout<<(chk ? "YES": "NO")<<endl;
	    }

	}
}	