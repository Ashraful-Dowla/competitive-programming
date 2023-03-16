/*
https://leetcode.com/problems/divide-two-integers/
*/
#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
	bool sign = (dividend>0) == (divisor>0);

	if(dividend==INT_MIN && divisor==-1) return INT_MAX;

	long _dividend = labs(dividend);
	long _divisor = labs(divisor);
	long ans=0;

	while(_dividend>=_divisor) {
		long temp = _divisor, m=1;

		while((temp<<1) <= _dividend){
			temp<<=1;
			m<<=1;
		}    

		_dividend-=temp;
		ans+=m;
	}

	return sign ? ans : -ans;
}

int main(){

	int dividend=2147483647, divisor = 2;
	cout<<divide(dividend,divisor)<<endl;
}