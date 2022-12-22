/*
https://codeforces.com/contest/1281/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s,c;
		cin>>s>>c;
		
		for(int i=0;i<s.size();++i){
			int idx=i;
			for(int j=s.size()-1;j>i;j--){
				if(s[j]<s[idx]){
					idx=j;
				}
			}
			if(idx!=i){
				swap(s[i],s[idx]);
				break;
			}
		}		
		if(s<c) cout<<s<<endl;
		else cout<<"---"<<endl;
	}
}