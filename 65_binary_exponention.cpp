#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M = 1e9+7;

ll binaryExp(ll a, ll b){
	if(b==0) return 1;
	ll res = binaryExp(a,b/2);
	if(b&1) return a*res*res;
	else return res*res;
}

ll binaryExpMod(ll a, ll b){
	if(b==0) return 1;
	ll res = binaryExpMod(a,b/2);
	if(b&1) return (a*(res*res)%M)%M;
	else return (res*res)%M;
}


// calculate a^b
// loop-> 0 .. b -> O(b)
// rec -> log(b) 

int main(){
	ll a = 222, b= 132;
	// cout<<binaryExp(a,b)<<endl;
	// cout<<pow(a,b)<<endl;
	cout<<binaryExpMod(a,b)<<endl;
}