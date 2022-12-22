/*
https://codeforces.com/problemset/problem/276/A
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;
int main(){
	int n,k;
	cin>>n>>k;
	vector<pr> res;
	int f_mx = -1e9;
	for(int i=0;i<n;++i){
		int f,t;
		cin>>f>>t;
		if(k>=t) f_mx = max(f_mx,f);
		else f_mx = max(f_mx, f-(t-k)); 
	}
	cout<<f_mx<<endl;
}