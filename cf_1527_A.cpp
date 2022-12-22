/*
https://codeforces.com/problemset/problem/1527/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int x;
	    cin>>x;
	    int i = log2(x);
	    cout<<(1<<i)-1<<endl;
	}
}