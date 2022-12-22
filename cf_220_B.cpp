/*
https://codeforces.com/problemset/problem/220/B
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int rootN;

struct Q
{
	int idx,l,r;	
};

bool comp(Q q1, Q q2){
	if(q1.l/rootN == q2.l/rootN){
		return q1.r>q2.r;
	}
	return q1.l/rootN < q2.l/rootN;
}

int main(){
	int n,m;
	// cin>>n>>m;
	scanf("%d %d",&n,&m);

	int arr[n];
	unordered_map<int,int>mp;
	unordered_map<int,bool>chk;
	for(int i=0;i<n;++i){
		// cin>>arr[i];
		scanf("%d",arr+i);
	}

	rootN = sqrtl(n);
	
	Q queries[m];

	for(int i=0;i<m;++i){
		int l,r;
		// cin>>l>>r;
		scanf("%d %d",&l,&r);
		queries[i].l=l;
		queries[i].r=r;
		queries[i].idx=i;
	}

	sort(queries,queries+m,comp);

	int ans[m];
	int curr_ans=0,curr_l=0,curr_r=-1,l,r;
	for(int i=0;i<m;++i){
		l=queries[i].l,r=queries[i].r;
		l--,r--;

		while(curr_r<r) {
		    curr_r++;
		    int val = ++mp[arr[curr_r]];
		    if(val==arr[curr_r]) {
		    	curr_ans++;
		    	chk[val]=true;
		    }
		    else if(chk[arr[curr_r]]){
		    	curr_ans--;
		    	chk[arr[curr_r]]=false;
		    }
		}

		while(curr_l>l){
			curr_l--;
			int val = ++mp[arr[curr_l]];
		    if(val==arr[curr_l]){
		    	 curr_ans++;
		    	 chk[val]=true;
		    }
		    else if(chk[arr[curr_l]]){
		    	curr_ans--;
		    	chk[arr[curr_l]]=false;
		    }
		}

		while(curr_l<l){
			int val = --mp[arr[curr_l]];
			if(val==arr[curr_l]) {
				curr_ans++;
				chk[val]=true;
			}
			else if(chk[arr[curr_l]]){
				curr_ans--;
				chk[arr[curr_l]]=false;
			} 
 			curr_l++;
		}

		while(curr_r>r){
			int val = --mp[arr[curr_r]];
			if(val==arr[curr_r]) {
				curr_ans++;
				chk[val]=true;
			}
			else if(chk[arr[curr_r]]){
				curr_ans--;
				chk[arr[curr_r]]=false;
			}
			curr_r--;
		}

		ans[queries[i].idx]=curr_ans;
	}

	for(int i=0;i<m;++i){
		// cout<<ans[i]<<endl;
		printf("%d\n",ans[i]);
	}

}	