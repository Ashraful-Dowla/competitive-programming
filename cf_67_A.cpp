/*
https://codeforces.com/contest/67/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;

int n;
string s;
int arr[N];

void generate(int idx){
	if(idx==s.size()) return ;

	if(s[idx]=='L'){
		if(arr[idx]<=arr[idx+1]){
			arr[idx]+=(arr[idx+1]-arr[idx])+1;
		}
		generate(idx+1);
		if(arr[idx]<=arr[idx+1]){
			arr[idx]+=(arr[idx+1]-arr[idx])+1;
		}
	}
	else if(s[idx]=='R'){
		if(arr[idx+1]<=arr[idx]){
			arr[idx+1]+=(arr[idx]-arr[idx+1])+1;
		}
		generate(idx+1);
		if(arr[idx+1]<=arr[idx]){
			arr[idx+1]+=(arr[idx]-arr[idx+1])+1;
		}
	}	
	else {
		arr[idx+1]=arr[idx];
		generate(idx+1);
		arr[idx]=arr[idx+1];
	}
}	

int main(){
	cin>>n;
	cin>>s;

	memset(arr,0,sizeof(arr));
	generate(0);

	for(int i=0;i<n;++i){
		cout<<arr[i]+1<<" ";
	}
}