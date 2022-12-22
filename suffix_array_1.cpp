#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int SA[N];
string s;
int sz;

bool comp(int a,int b){
	string s_a = s.substr(a,sz-a);
	string s_b = s.substr(b,sz-b);
	return s_a<s_b;
}

int main(){

	cin>>s;
	sz=s.size();

	for(int i=0;i<sz;++i){
		SA[i]=i;
	}

	sort(SA,SA+sz,comp); // nlog(n)*n = n^2log(n);

	for(int i=0;i<sz;++i){
		cout<<SA[i]<<" "<<s.substr(SA[i],sz-SA[i])<<endl;
	}
}