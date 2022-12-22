/*
https://codeforces.com/problemset/problem/416/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	long long start=-2e9,end=2e9;
	while(t--){
		string inq,str;
		long long num;
		cin>>inq>>num>>str;
		if(inq==">="){
			if(str=="Y") start = max(start, num);
			else end = min(end,num-1);
		}
		else if(inq==">"){
			if(str=="Y") start = max(start, num+1);
			else end = min(end,num);
		}
		else if(inq=="<="){
			if(str=="Y") end = min(end, num);
			else start = max(start, num+1);
		}
		else {
			if(str=="Y") end = min(end,num-1);
			else start = max(start, num);
		}
	}
	if(start>end) cout<<"Impossible"<<endl;
	else cout<<start<<endl;
}