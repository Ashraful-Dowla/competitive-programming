/*
https://codeforces.com/problemset/problem/25/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	string num;
	cin>>num;

	string ans="";
	if(n<=3) {
		cout<<num<<endl;
		return 0;
	}

	int cnt=0;
	if(n&1) cnt = (n-3)/2;
	else cnt = (n/2)-1;

	for(int i=0;i<n;++i){
		ans.push_back(num[i]);
		if(i&1 && cnt){
			ans.push_back('-');
			cnt--;
		}
	}
	cout<<ans<<endl;
	return 0;
}