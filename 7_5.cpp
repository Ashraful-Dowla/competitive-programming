/*
https://leetcode.com/problems/student-attendance-record-i/
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int absent = 0, late=0, consecutive=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='A') {
			absent++;
			late=0;
		}
		else if(s[i]=='L') {
			late++;
			if(late==3) consecutive++;
		}
		else late=0;
	}

	cout<<(absent<2 && consecutive==0)<<endl;
}