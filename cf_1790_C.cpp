/*
https://codeforces.com/contest/1790/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;

	int arr[n][n];
	for(int i=0;i<n;++i){
		for(int j=0;j<n-1;++j){
			cin>>arr[i][j];
		}
	}

	int cnt[n+2],ans[n],idx=0;
	bool taken[n+2];

	memset(taken,false,sizeof(taken));

	for(int i=0;i<n-1;++i){
		memset(cnt,0,sizeof(cnt));

		set<int>temp;
		for(int j=0;j<n;++j){
			cnt[arr[j][i]]++;
			if(!taken[arr[j][i]]){
				temp.insert(arr[j][i]);
			}
		}

		if(temp.size()==1){
			int val = *(--temp.end());
			ans[idx++]= val;
			taken[val]=true;
		}
		else {
			int f_val = *(temp.begin());
			int s_val = *(--temp.end());

			if(cnt[f_val]>cnt[s_val]){
				ans[idx++]= f_val;	
				ans[idx++]= s_val;	
				taken[f_val]=taken[s_val]=true;
			}
			else {
				ans[idx++]= s_val;	
				ans[idx++]= f_val;	
				taken[f_val]=taken[s_val]=true;
			}
		}

	}

	for(int i=0;i<n;++i){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}