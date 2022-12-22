/*
https://codeforces.com/contest/1102/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin>>n;
	long long sum = (n*(n+1))/2;
	cout<<sum%2<<endl;
}