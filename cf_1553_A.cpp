/*
https://codeforces.com/problemset/problem/1553/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int num;
	    cin>>num;

	    if(num<9) {
	    	cout<<0<<endl;
	    	continue;
	    }

	    while(num%10!=9){
	    	--num;
	    }

	    int n = ((num-9)/10)+1;

	    cout<<n<<endl;
	}
}