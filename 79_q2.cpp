/*
https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/xor-challenge-2420f189/
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int c;
	cin>>c;

	int bit_cnt = (int)log2(c) + 1;
	int a=0,b=0;
	vector<int>set_bits;
	for(int i=0;i<bit_cnt;++i){
		if(c&(1<<i)) {
			set_bits.push_back(i);
		}
		else {
			a|=(1<<i);
			b|=(1<<i);
		}
	}

	long long ans=-1;
	int sz = (1<<set_bits.size());
	for(int mask=0;mask<sz;++mask){
		long long a_copy=a,b_copy=b;
		for(int i=0;i<set_bits.size();++i){
			if(mask&(1<<i)) a_copy|=(1<<set_bits[i]);
			else b_copy|=(1<<set_bits[i]);
		}
		ans = max(ans, a_copy*1LL*b_copy);
	}
	cout<<ans<<endl;
}