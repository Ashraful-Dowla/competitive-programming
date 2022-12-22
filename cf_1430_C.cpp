/*
https://codeforces.com/problemset/problem/1430/C
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int b=n;
	    cout<<2<<endl;
	    for(int i=n-1;i>=1;--i){
	    	cout<<i<<" "<<b<<endl;
	    	b = (b+i+1)/2;
	    }
	}
}