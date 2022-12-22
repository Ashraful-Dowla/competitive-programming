/*
https://codeforces.com/contest/653/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;
bool arr[N];


int main(){
	int n;
	cin>>n;
	vector<int>vec;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		if(arr[x]) continue;
		arr[x]=true;
		vec.push_back(x);
	}

	sort(vec.begin(),vec.end());

	if(vec.size()<3) {
		cout<<"NO"<<endl;
		return 0;
	}

	bool isPossible=false;
	n=vec.size();
	for(int i=0;i<n-2;++i){
		int cnt=1;
		for(int j=i+1;j<n;++j){
			if(vec[j]-vec[i]<=2) cnt++;
		}
		isPossible|=(cnt>=3);
		if(isPossible) break;
	}

	cout<<(isPossible ? "YES": "NO")<<endl;
}