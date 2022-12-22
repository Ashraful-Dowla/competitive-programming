#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int l,r,m;
	    cin>>l>>r>>m;

	    for(int a=l;a<=r;a++){
	    	int x = m%a;
	    	if(a-x<=r-l){
	    		cout<<a<<" "<<l<<" "<<l+a-x<<endl;
	    		break;
	    	}
	    	if(x<=r-l){
	    		cout<<a<<" "<<l+x<<" "<<l<<endl;
	    		break;
	    	}
	    }

	}
}