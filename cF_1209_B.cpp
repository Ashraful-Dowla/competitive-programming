/*
https://codeforces.com/problemset/problem/1209/B
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1200;
typedef pair<int,int> pr;

int main(){
	int n;
	cin>>n;

	string s;
	cin>>s;

	vector<pr> vec;
	for(int i=0;i<n;++i) {
		int a,b;
		cin>>a>>b;
		vec.push_back({a,b});
	}

	int arr[105][N];
	memset(arr,0,sizeof(arr));

	for(int i=0;i<vec.size();++i){
		int a=vec[i].first;
		int b=vec[i].second;

		int st;
		if(s[i]=='1'){
			for(int l=0;l<b;++l){
				arr[i][l]=1;
			}
			st=b+a;
		}
		else st=b;

		for(int j=st;j<130;j+=2*a){
			for(int k=j;k<j+a;++k){
				arr[i][k]=1;
			}
		}
	}

	int mx=0;
	for(int i=0;i<N;++i){
		int cnt=0;
		for(int j=0;j<n;++j){
			cnt+=arr[j][i];
		}
		mx=max(mx,cnt);
	}
	cout<<mx<<endl;
}