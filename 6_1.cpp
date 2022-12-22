/*
  https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

	string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

	int a,b;
	cin>>a>>b;

	for(int i=a;i<=b;i++){
		if(i<10) cout<<arr[i]<<endl;
		else if(i%2==0) cout<<"even"<<endl;
		else cout<<"odd"<<endl;
	}
}