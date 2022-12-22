#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int p=31,MOD=1e9+7;

//p->prime
//s->pattern
//t->text

//time complexity -> O(S+T)
vector<int> rabin_karp(string s,string t){
	int S=s.size(),T=t.size();

	vector<ll>p_pow(max(S,T));
	p_pow[0]=1;

	for(int i=1;i<p_pow.size();++i){
		p_pow[i] =(p_pow[i-1]*p)%MOD;
	}

	vector<ll>h(T+1,0);
	for(int i=0;i<T;++i){
		h[i+1] = (h[i] + (t[i]-'A'+1)*p_pow[i])%MOD;
	}

	ll hsh=0;
	for(int i=0;i<S;++i){
		hsh = (hsh + (s[i]-'A'+1)*p_pow[i])%MOD;
	}

	vector<int>occurences;
	for(int i=0;i+S-1<T;++i){
		ll curr_h = (h[i+S] - h[i] + MOD)%MOD;

		//curr_h/p_pow[i] = hsh
		if(curr_h==(hsh*p_pow[i])%MOD){
			occurences.push_back(i);
		}
	}

	return occurences;
}

int main(){
	string s,t;
	getline(cin,s);
	getline(cin,t);

	vector<int> ans = rabin_karp(s,t);

	for(auto val: ans){
		cout<<val<<" ";
	}
	cout<<endl;
}