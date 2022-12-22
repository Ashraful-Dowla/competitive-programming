/*
https://codeforces.com/problemset/problem/1490/D
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e2+10;
int depth[N],cnt;

void generate(int l,int r, vector<int> &vec){
	auto it = max_element(vec.begin()+l,vec.begin()+r+1);
	int mid = it-vec.begin();
	depth[*it]=cnt;
	
	cnt++;
	if(l==r) return;
	if(l<=mid-1) {
		generate(l,mid-1,vec);
		cnt--;
	}
	if(mid+1<=r) {
		generate(mid+1,r,vec);
		cnt--;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--) {
	   int n;
	   cin>>n;
	   vector<int>vec(n);
	   for(int i=0;i<n;++i){
	   	 cin>>vec[i];
	   }
	   cnt=0;
	   generate(0,n-1,vec);
	   for(int i=0;i<n;++i){
	   	  cout<<depth[vec[i]]<<" ";
	   }
	   memset(depth,0,sizeof(depth));
	   cout<<endl;
	}
}
