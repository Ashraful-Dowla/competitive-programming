/*
https://codeforces.com/problemset/problem/272/A
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
bool arr[N];

int main(){
	int n;
	cin>>n;
	int frnd_sum=0;
	for(int i=1;i<=N;i+=(n+1)) arr[i]=true;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		frnd_sum+=x;
	}
	int ct=0;
	for(int i=1;i<=5;++i){
		if(!arr[i+frnd_sum]) ct++;
	}
	cout<<ct<<endl;
}