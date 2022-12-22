#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int rootN;

struct Q
{	
 	int idx,l,r;
};

Q queries[N];

bool comp(Q q1, Q q2){
	if(q1.l/rootN == q2.l/rootN){
		return q1.r>q2.r;
	}
	return q1.l/rootN < q2.l/rootN;
}

int main(){
	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;++i){
		cin>>arr[i];
	}

	rootN = sqrtl(n);

	int q;
	cin>>q;
	for(int i=0;i<q;++i){
		int l,r;
		cin>>l>>r;
		queries[i].l=l;
		queries[i].r=r;
		queries[i].idx=i;
	}

	sort(queries,queries+q,comp);
	
	int ans[q];
	int curr_l=0,curr_r=-1,l,r;
	int curr_ans=0;

	for(int i=0;i<q;++i){
		l = queries[i].l,r=queries[i].r;
		l--,r--;

		while(curr_r<r) {
			curr_r++;
		    curr_ans+=arr[curr_r];
		}

		while(curr_l>l){
			curr_l--;
			curr_ans+=arr[curr_l];
		}

		while(curr_l<l){
			curr_ans-=arr[curr_l];
			curr_l++;
		}

		while(curr_r>r){
			curr_ans-=arr[curr_r];
			curr_r--;
		}

		ans[queries[i].idx]=curr_ans;
	}

	for(int i=0;i<q;++i){
		cout<<ans[i]<<endl;
	}
}