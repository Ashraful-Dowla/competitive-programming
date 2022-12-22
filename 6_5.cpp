/*
https://www.hackerrank.com/challenges/fizzbuzz/problem
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	for(int i=1;i<=100;i++){
		string output="";
		if(i%3==0) output+="Fizz";
		if(i%5==0) output+="Buzz";
		output=="" ? cout<<i<<endl : cout<<output<<endl;
	}
}