/*
https://leetcode.com/problems/multiply-strings/description/
*/
#include <bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2) {

	if(num1.size()<num2.size()) swap(num1,num2);

	int sz=3*num1.size();
	int ans[sz];	
	memset(ans, 0, sizeof(ans));

	int t=0;
	for(int i=num2.size()-1;i>=0;--i){
		int carry=0, k=t++;
		for(int j=num1.size()-1;j>=0;--j){
			int val = (num2[i]-'0')*(num1[j]-'0') + carry;
			carry=val/10;
			ans[k]+=val%10;
			k++;

		}
		ans[k]+=carry;
	}

	for(int i=0;i+1<sz;++i){
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
	}

	string res="";
	bool chk=true;
	for(int i=sz-1;i>=0;--i){
		if(ans[i]==0 && chk) continue;
		res+=to_string(ans[i]);
		chk=false;
	}

	return res.size() ? res: "0";
}

int main(){
	string num1 = "1234";
	string num2 = "1";

	cout<<multiply(num1,num2)<<endl;
}