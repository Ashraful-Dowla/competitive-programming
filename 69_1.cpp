//https://leetcode.com/problems/super-pow/
#include <bits/stdc++.h>
using namespace std;

const int M=1337; 
const int fi=1140; // fi(1337) = 1140

int binaryExp(int a,int b, int m){
	int ans=1;
	while(b){
		if(b&1) ans=(ans*1LL*a)%m;
		a=(a*1LL*a)%m;
		b>>=1;
	}
	return ans;
}

int powerMod(vector<int> &b){
	int pw=0,ans=0;
	for(int i=b.size()-1;i>=0;--i){
		ans=(ans+(binaryExp(10,pw,fi)*1LL*b[i])%fi)%fi;
		pw++;
	}
	return ans;
}

int superPow(int a, vector<int>& b) {
    return binaryExp(a,powerMod(b),M);
}

int main(){
	int a=2;
	vector<int>b={1,0};
	cout<<superPow(a,b)<<endl;
}