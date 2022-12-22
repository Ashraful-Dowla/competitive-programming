/*
https://codeforces.com/problemset/problem/1514/A
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e4;
bool perfect_square[N*N];

void precompute_perfect_square(){
	for(int i=1;i<=N;++i){
		perfect_square[i*i]=true;
	}
}

int main(){
	precompute_perfect_square();
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int arr[n];
	    bool chk=false;
	    for(int i=0;i<n;++i){
	    	cin>>arr[i];
	    	if(!perfect_square[arr[i]]) chk=true;
	    }
	    cout<<(chk ? "YES": "NO")<<endl;
	}
}