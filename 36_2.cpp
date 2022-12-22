/*
https://www.hackerearth.com/problem/algorithm/the-monk-and-class-marks/?fbclid=IwAR09BMLG-1NhqDlVQq0KIzSr8ZTgqrbJmdfnsXc7KnDiphgX5UmbFLoEYjE
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<string,int> pr;


void prntVector(vector<pr> &vec){
	for(pr value:vec){
		cout<<value.first<<" "<<value.second<<endl;
	}
}

bool comp(pr a, pr b){
	if(a.second == b.second){
		return a.first<b.first;
	}
	return a.second>b.second;
}

int main(){
	int n;
	cin>>n;
	vector<pr>vec;
	for(int i=0;i<n;i++){
		string s;
		int num;
		cin>>s>>num;
		vec.push_back({s,num});
	}

	sort(vec.begin(),vec.end(),comp);
	prntVector(vec);
}