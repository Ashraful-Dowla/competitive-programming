/*
https://codeforces.com/contest/116/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;

	string ground[n];
	for(int i=0;i<n;++i){
		cin>>ground[i];
	}

	vector<pair<int,int>>vec;
	vec.push_back({0,0});

	for(int i=0;i<n;++i){
		if(i%2==0){
			for(int j=0;j<m;++j){
				if(ground[i][j]=='W') vec.push_back({i,j});
			}
		}
		else {
			for(int j=m-1;j>=0;--j){
				if(ground[i][j]=='W') vec.push_back({i,j});
			}
		}
	}

	int res=0;
	for(int i=0;i<vec.size()-1;++i){
		int n1=vec[i].first;
		int m1=vec[i].second;
		int n2=vec[i+1].first;
		int m2=vec[i+1].second;
		res+=n2-n1+abs(m1-m2);
	}

	cout<<res<<endl;
}