/*
https://www.codechef.com/LRNDSA01/problems/FLOW007
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool chk=false;
		while(n){
			int last_digit=n%10;
			n/=10;
			if(last_digit==0 && !chk) continue;
			else {
				cout<<last_digit;
				chk=true;
			}
		}
		cout<<endl;
	}
}