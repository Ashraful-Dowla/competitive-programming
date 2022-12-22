/*
https://codeforces.com/problemset/problem/489/C
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int m,s;
	cin>>m>>s;

	if(s==0) {
		cout<<(m==1 ? "0 0": "-1 -1")<<endl;
		return 0;
	}

	string mx_number;
	for(int i=0;i<m;++i){
		int digit = min(9,s);
		mx_number.push_back(digit+'0');
		s-=digit;
	}

	if(s>0){
		cout<<"-1 -1"<<endl;
		return 0;
	}

	string min_number = mx_number;
	reverse(min_number.begin(),min_number.end());

	if(min_number[0]=='0'){
		int idx=1;
		min_number[0]= '1';
		for(int i=1;i<min_number.size();++i){
			if(min_number[i]!='0'){
				min_number[i]= ((min_number[i] - '0')-1) +'0';
				break;
			}
		}
	}	
	cout<<min_number<<" "<<mx_number<<endl;
	return 0;

}