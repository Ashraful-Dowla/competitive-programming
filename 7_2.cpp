/*
https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/palindrome-check-2/
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]==s[s.size()-i-1]) continue;
		else {
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}