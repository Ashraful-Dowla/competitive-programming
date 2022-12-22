#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int b[N];
string s,t;

//time complexity -> O(m)
void kmpPreprocess(){
	int i=0,j=-1,m=s.size();
	b[0]=-1;

	while(i<m){
		while(j>=0 && s[i]!=s[j]){
			j=b[j];
		}
		i++,j++;
		b[i]=j;
	}
}

//time complexity -> O(n+m)
void kmpSearch(){
	int i=0,j=0,n=t.size();
	while(i<n){
		while(j>=0 && t[i]!=s[j]){
			j=b[j];
		}
		i++,j++;
		if(j==s.size()) {
			cout<<i-j<<endl;
			j=b[j];
		}
	}
}

int main(){
	getline(cin,s);
	kmpPreprocess();
	getline(cin,t);
	kmpSearch();	
}