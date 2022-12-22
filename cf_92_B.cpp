/*
https://codeforces.com/problemset/problem/92/B
*/
#include<bits/stdc++.h>
using namespace std;
	
int main(){
	string s;
	cin>>s;

	int cnt=0;
	int i=s.size()-1;
	while(i>0){
		if(s[i]=='1'){
			while(true) {
			    if(i==-1 || s[i]=='0'){
			    	if(i!=-1) s[i]='1';
			    	cnt++;
			    	break;
			    }
			    --i;
			    cnt++;
			}
		}
		else {
			cnt++;
			--i;
		}
	}
	cout<<cnt<<endl;
}