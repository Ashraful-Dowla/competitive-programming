/*
https://codeforces.com/contest/1788/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"

const int N=1e5+10;
const int MOD=1e9+7;

void prnt(vector<int> &vec){
	int z=0;
	for(int i=0;i<vec.size();++i){
		if(vec[i]!=0){
			z++;
			cout<<vec[i];
		}
		else if(vec[i]==0 && z){
			cout<<vec[i];
		}
	}

	if(z==0) cout<<0;
}


void solve(){
	string s;
	cin>>s;

	vector<int>first,second;
	int chk=1;
	for(int i=0;i<s.size();++i){
		int digit = s[i]-'0';

		if(digit%2==0){
			first.push_back(digit/2);
			second.push_back(digit/2);
		}
		else {
			if(chk){
				first.push_back(digit/2);
				second.push_back(1+digit/2);
			}
			else {
				first.push_back(1+digit/2);
				second.push_back(digit/2);
			}
			chk^=1;
		}
	}

	prnt(first);
	cout<<" ";
	prnt(second);
	cout<<endl;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}