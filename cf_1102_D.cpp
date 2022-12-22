/*
https://codeforces.com/problemset/problem/1102/D
*/
#include <bits/stdc++.h>
using namespace std;

int n;
string str;

vector<int>cnt(3);

void assignVal(int n){
	fill(cnt.begin(),cnt.end(),-1*(n/3));
}

void forward(int x){
	for(int i=0;i<n;++i){
		int cur_val = str[i]-'0';
		if(cnt[x]<0 && x<cur_val && cnt[cur_val]>0){
			cnt[x]++;
			cnt[cur_val]--;
			str[i]=x+'0';
		}
	}
}

void backward(int x){
	for(int i=n-1;i>=0;--i){
		int cur_val = str[i]-'0';
		if(cnt[x]<0 && x>cur_val && cnt[cur_val]>0){
			cnt[x]++;
			cnt[cur_val]--;
			str[i]=x+'0';
		}
	}
}

int main(){
	cin>>n;
	assignVal(n);
	cin>>str;
	for(char c: str){
		cnt[c-'0']++;
	}

	forward(0);
	forward(1);
	backward(2);
	backward(1);

	cout<<str<<endl;
}