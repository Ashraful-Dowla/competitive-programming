/*
https://www.hackerearth.com/problem/algorithm/gpl/
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		long long sum=0;
		for(int i=n-1;i>=0;i--){
			long long pw = pow(2,i);
			sum = sum + pw*(s[n-i-1]-'0');
		}
		cout<<sum<<endl;
	}
}