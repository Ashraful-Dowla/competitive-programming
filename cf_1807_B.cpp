#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"

const int N=1e5+10;
const int MOD=1e9+7;

void solve(){
	int n;
	cin>>n;

	int even=0,odd=0;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;

		if(x%2==0) even+=x;
		else odd+=x;
	}

	if(even>odd) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}