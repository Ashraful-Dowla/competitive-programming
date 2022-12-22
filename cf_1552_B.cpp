/*
https://codeforces.com/problemset/problem/1552/B
*/
#include <bits/stdc++.h>
using namespace std;

const int M=5;

struct Rank{
	int r[M];
};

bool operator<(const Rank &A, const Rank &B){
	int cnt=0;
	for(int i=0;i<M;++i){
		cnt+=(A.r[i]<B.r[i]);
	}
	return cnt>=3;
}

int main(){
	int t;
	cin>>t;

	while(t--){
	    int n;
	    cin>>n;

	    vector<Rank> athelet(n);

	    for(int i=0;i<n;++i){
	    	for(int j=0;j<M;++j){
	    		cin>>athelet[i].r[j];
	    	}
	    }

	    int wn=0;
	    for(int i=1;i<n;++i){
	    	if(athelet[i]<athelet[wn]) wn=i;
	    }

	    bool chk=true;
	    for(int i=0;i<n;++i){
	    	if(i==wn) continue;
	    	if(athelet[i]<athelet[wn]){
	    		chk=false;
	    		break;
	    	}
	    }

	    cout<<(chk? wn+1:-1)<<endl;
	}
}