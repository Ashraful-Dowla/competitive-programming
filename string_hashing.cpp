#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+10,MOD=1e9+7;
vector<ll>powers(N);

int p=31;

int calc_hash(string s){
	ll hsh_val=0;
	for(int i=0;i<s.size();++i){
		hsh_val = (hsh_val+(s[i]-'a'+1)*powers[i])%MOD;
	}
	return hsh_val;
}

int main(){
	vector<string>str = {"aa","ab","b","cc","aa"};

	powers[0]=1;
	for(int i=1;i<N;++i){
		powers[i]= (powers[i-1]*p)%MOD;
	}

	vector<ll>hsh;

	// time complexity -> O(nm);
	for(auto s: str){
		hsh.push_back(calc_hash(s));
	}

	// time complexity -> O(nlogn);
	sort(hsh.begin(),hsh.end());
	int distinct=0;

	for(int i=0;i<hsh.size();++i){
		if(i==0 || hsh[i]!=hsh[i-1]) distinct++;
	}
	cout<<distinct<<endl;
}