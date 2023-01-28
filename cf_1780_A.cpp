/*
https://codeforces.com/contest/1780/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;

	vector<int> even,odd;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		if(x&1) odd.push_back(i+1);
		else even.push_back(i+1);
	}


	if(odd.size()>=3){
		cout<<"YES"<<endl;
		cout<<odd[0]<<" "<<odd[1]<<" "<<odd[2]<<endl;
	}
	else if(odd.size()>=1 && even.size()>=2){
		cout<<"YES"<<endl;
		cout<<odd[0]<<" "<<even[0]<<" "<<even[1]<<endl;
	}
	else cout<<"NO"<<endl;
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    solve();
	}
}