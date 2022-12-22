/*
https://codeforces.com/contest/1760/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int x,y,z;
	    cin>>x>>y>>z;
	    vector<int> vec;
	    vec.push_back(x);
	    vec.push_back(y);
	    vec.push_back(z);

	    sort(vec.begin(),vec.end());
	    cout<<vec[1]<<endl;
	}
}	