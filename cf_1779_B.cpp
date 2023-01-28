/*
https://codeforces.com/contest/1779/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

vector<int>odd;
void odd_list(){
	for(int i=5;i<=1000;i+=2){
		odd.push_back(i);
	}
}

void solve(){
	int n;
	cin>>n;

	if(n==3){
		cout<<"NO"<<endl;
		return ;
	}

	cout<<"YES"<<endl;
	if(n&1) {
		auto it = lower_bound(odd.begin(),odd.end(),n);
		int j = it-odd.begin()+1;
		for(int i=0;i<n/2;++i){
			cout<<j<<" "<<-(j+1)<<" "; 
		}
		cout<<j<<endl;
	}
	else {
		for(int i=0;i<n/2;++i){
			cout<<"1 -1 ";
		}
		cout<<endl;
	}
}

int main(){
	int t;
	cin>>t;

	odd_list();

	while(t--){
		solve();
	}
}