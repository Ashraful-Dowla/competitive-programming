/*
https://codeforces.com/contest/1782/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

void solve(){
	int w,d,h;
	cin>>w>>d>>h;
	int a,b,f,g;
	cin>>a>>b>>f>>g;

	int m1;
	if(b+g<2*d-b-g){
		m1 = b + h + g + abs(a-f);
	}
	else {
		m1 = 2*d-b-g + h  + abs(a-f);
	}

	int m2;
	if(a+f<2*w-a-f){
		m2 = a + h + f + abs(b-g);
	}
	else {
		m2 = 2*w-a-f + h + abs(b-g);
	}

	cout<<min(m1,m2)<<endl;
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    solve();
	}
}