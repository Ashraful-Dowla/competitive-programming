/*

*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int mn=1e5+10;
	for(char ch='a';ch<='z';ch++){
		int k=0,t=0;
		for(int i=0;i<=s.size();++i){
			k = max(k,++t);
			if(s[i]==ch) t=0;
		}
		mn = min(mn,k);
	}
	cout<<mn<<endl;
}