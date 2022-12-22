#include <bits/stdc++.h>
using namespace std;

int digit_sum(long long n){
	if(n==0) return 0;
	return (n%10) + digit_sum(n/10);
}

int calculate(long long n){
	long long val = digit_sum(n);
	if(val<10) return val;
	return calculate(val);
}

int superDigit(string n, int k) {
	long long sum=0;
	for(int i=0;i<n.size();i++){
		sum+=(n[i]-'0');
	}
	
	return calculate(sum*k);
}

int main(){
	string n;
	int k;
	cin>>n>>k;
	cout<<superDigit(n,k)<<endl;
}