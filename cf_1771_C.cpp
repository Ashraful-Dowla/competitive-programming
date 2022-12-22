#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool solve(){
	int n;
	cin>>n;

	ll arr[n];
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}

	bool chk=false;

	for(int i=1;i<n;++i){
		if(__gcd(arr[0],arr[i])>1){
			chk=true;
			break;
		}
	}

	for(int i=0;i<n-1;++i){
		if(__gcd(arr[n-1],arr[i])>1){
			chk=true;
			break;
		}
	}

	for(int i=1;i<n;++i){
		if(__gcd(arr[i],arr[i-1])>1){
			chk=true;
			break;
		}
	}

	return chk;
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    cout<<(solve() ? "YES":"NO")<<endl;
	}
}