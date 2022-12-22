/*
https://codeforces.com/contest/1037/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

string a,b;
int main(){
	int n;
	cin>>n;
	cin>>a>>b;

	int ans=0;
	for(int i=0;i<n;++i){
		if(a[i]==b[i]) continue;

		if(i+1<n && a[i]==b[i+1] && a[i+1]==b[i]) i++;
		ans++;
	}
	cout<<ans<<endl;
}