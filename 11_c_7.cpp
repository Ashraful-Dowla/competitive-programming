/*
https://www.hackerearth.com/problem/algorithm/too-lazy-to-name-the-question/
*/
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a: gcd(b,a%b);
}
int lcm(int a, int b) {
	return a*(b/gcd(a,b));
}

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int al=1, bl = 1, nth_value;
	for(int i=0;i<c;i++){
		long long aV = a*al;
		long long bV = b*bl;
		if(aV<bV){
			al++;
			nth_value = aV;
		}
		else if(aV>bV){
			bl++;
			nth_value = bV;
		}
		else {
			al++;
			bl++;
			nth_value = aV;
		}
	}
	long long step_value;
	if(nth_value %a==0 && nth_value%b==0) step_value = lcm(a,b);
	else if(nth_value%a ==0) step_value = a;
	else step_value = b;

	while(true){
		cout<<nth_value<<" ";
		if(nth_value ==0) break;
		nth_value-=step_value;
	}
	cout<<endl;
}