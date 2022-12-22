/*
https://codeforces.com/problemset/problem/1393/B
*/
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int num[N];

int main(){
	int n;
	cin>>n;
	int cnt2=0,cnt4=0;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		cnt2-=num[x]/2;
		cnt4-=num[x]/4;
		num[x]++;
		cnt2+=num[x]/2;
		cnt4+=num[x]/4;
	}

	int q;
	cin>>q;
	while(q--) {
	    char ch;
	    int x;
	    cin>>ch>>x;
	    cnt2-=num[x]/2;
		cnt4-=num[x]/4;
		if(ch=='+') num[x]++;
		else num[x]--;
		cnt2+=num[x]/2;
		cnt4+=num[x]/4;

		if(cnt2>=4 && cnt4>=1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}