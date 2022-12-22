/*
https://codeforces.com/problemset/problem/1217/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
		int str,intl, expn;
		cin>>str>>intl>>expn;
		int minAdds = expn + intl - str + 2;
		minAdds/=2;
		minAdds = max(0,minAdds);

		cout<<max(0,expn-minAdds+1)<<endl;
	}
}