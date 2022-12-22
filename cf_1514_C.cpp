/*
https://codeforces.com/submissions/Ashraf_Koushik
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	vector<int> ans;

	int x=1;
	for(int i=1;i<n;++i){
		if(__gcd(i,n)==1){
			ans.push_back(i);
			x=(x*1LL*i)%n;
		}
	}

	if(x!=1) ans.pop_back();

	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();++i){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}