/*
https://codeforces.com/problemset/problem/599/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int d1,d2,d3;
	cin>>d1>>d2>>d3;
	int ans = 2*d1+2*d2;
	ans = min(ans,d1+d2+d3);
	ans = min(ans,2*d1+2*d3);
	ans = min(ans,2*d2+2*d3);
	cout<<ans<<endl;
}