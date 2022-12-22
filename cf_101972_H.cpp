#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int hsh[N][30];

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int n,m,k;
	    cin>>n>>m>>k;
	    string a;
	    cin>>a;
	    string b;
	    cin>>b;

	    memset(hsh,0,sizeof(hsh));

	    for(int i=0;i<m;++i){
	    	hsh[i][b[i]-'a']++;
	    }

	    for(int i=m-2;i>=0;--i){
	    	for(int j=0;j<26;++j){
	    		hsh[i][j]+=hsh[i+1][j];
	    	}
	    }

	    for(int i=0;i<m;++i){
	    	for(int j=0;j<5;++j){
	    		cout<<hsh[i][j]<<" ";
	    	}
	    	cout<<endl;
	    }

	    bool first[30],last[30];
	    memset(first,false,sizeof(first));
	    memset(last,false,sizeof(last));

	    for(int i=0;i<=n-k;++i){
	    	first[a[i]-'a']=true;
	    	last[a[i+k-1]-'a']=true;
	    }
	}
}