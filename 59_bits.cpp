#include <bits/stdc++.h>
using namespace std;

void printBinary(int num){
	for(int i=10;i>=0;i--){
		cout<<((num>>i)&1);
	}
	cout<<endl;
}

int main(){
	int a = 9;
	int i = 0;

	//check bit set or not
	if((a&(1<<i))!=0) cout<<"set bit"<<endl;
	else cout<<"not set bit"<<endl;

	printBinary(a);
	//bit set
	printBinary(a|(1<<i));

	//bit unset
	printBinary(a&(~(1<<i)));

	//toggle
	printBinary(a^(1<<i));

	int cnt=0;
	for(int i=31;i>=0;i--){
		if((a&(1<<i))!=0) cnt++;
	}
	cout<<cnt<<endl;

	cout<<__builtin_popcount(a)<<endl;
	cout<<__builtin_popcountll(1LL<<35)<<endl;
}