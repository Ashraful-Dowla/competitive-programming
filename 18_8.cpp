/*
https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/little-jhool-and-the-magical-jewels/
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int arr[30];

		arr['r'-'a'] = 0;
		arr['u'-'a'] = 0;
		arr['b'-'a'] = 0;
		arr['y'-'a'] = 0;

		for(int i=0;i<s.size();i++){
			arr[s[i]-'a']++;
		}

		string sh = "ruby";
		int mx = s.size();
		for(int i=0;i<sh.size();i++){
			mx = min(mx, arr[sh[i]-'a']);
		}
		cout<<mx<<endl;
	}
}