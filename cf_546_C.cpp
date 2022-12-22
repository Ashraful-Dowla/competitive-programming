/*
https://codeforces.com/contest/546/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	int k1,k2;
	cin>>k1;
	deque<int> dq1, dq2;

	for(int i=0;i<k1;++i){
		int x;
		cin>>x;
		dq1.push_back(x);
	}
	cin>>k2;
	for(int i=0;i<k2;++i){
		int x;
		cin>>x;
		dq2.push_back(x);
	}

	int cnt=0;
	while(!dq1.empty() && !dq2.empty() && cnt<=n*n*n) {
	   int t1 = dq1.front();
	   int t2 = dq2.front();

	   dq1.pop_front(),dq2.pop_front();

	   if(t1>t2){
	   	  dq1.push_back(t2);
	   	  dq1.push_back(t1);
	   }
	   else {
	   	  dq2.push_back(t1);
	   	  dq2.push_back(t2);
	   }
	   cnt++;
	}

	if(dq1.empty()) cout<<cnt<<" "<<2<<endl;
	else if(dq2.empty()) cout<<cnt<<" "<<1<<endl;
	else cout<<-1<<endl;
}