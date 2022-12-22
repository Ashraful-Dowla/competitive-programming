/*
https://codeforces.com/problemset/problem/610/A
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	long n;
	cin>>n;
	if(n%2==0){
		n%4 ==0 ? cout<<(n/4)-1<<endl : cout<<(n/4)<<endl;
	}else cout<<0<<endl;
}