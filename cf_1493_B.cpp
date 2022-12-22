/*
https://codeforces.com/contest/1493/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

vector<int>digits = {0,1,5,-1,-1,2,-1,-1,8,-1};

string resz(int x){
	string str = to_string(x);
	if(str.size()==1) str="0"+str;
	return str;
}

int gen(int x){
	string str = resz(x);
	int res=0;
	for(int i=1;i>=0;--i){
		int val = str[i]-'0';
		if(digits[val]==-1) return INT_MAX;
		res+=pow(10,i)*digits[val];
	}
	return res;
}

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int h,m;
	    cin>>h>>m;
	    string clck;
	    cin>>clck;
	    int _h = stoi(clck.substr(0,2));
	    int _m = stoi(clck.substr(3,2));

	    while(true){
	    	if(_m==m) _h++,_m=0;
	    	if(_h==h)  _h=0;

	    	if(gen(_m)<h && gen(_h)<m){
	    		cout<<resz(_h)<<":"<<resz(_m)<<endl;
	    		break;
	    	}
	    	_m++;
	    }
	}
}