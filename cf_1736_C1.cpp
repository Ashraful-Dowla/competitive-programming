#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int n;
	    cin>>n;
	    vector<int>vec;

	    for(int i=0;i<n;++i){
	    	int x;
	    	cin>>x;
	    	vec.push_back(x);
	    }

	    sort(vec.begin(),vec.end());

	    int cnt=0;
	 	for(int i=1;i<=n;++i){
	 		auto it = lower_bound(vec.begin(),vec.end(),i);
	 		if(it!=vec.end()) {
	 			int t=it-vec.begin();
	 			cout<<t<<endl;
	 			cnt+=(n-t);
	 		}
	 	}
	 	cout<<cnt<<endl;   
	}
}