#include <bits/stdc++.h>
using namespace std;

int main(){
	int lo=1,hi=1e6,ans=-1;

	while(lo<=hi) {
	    int mid = (lo+hi)/2;
	    cout<<mid<<endl;
	    cout<<flush;

	    string s;
	    cin>>s;

	    if(s=="<") hi = mid -1;
	    else {
	    	ans=max(ans,mid);
	    	lo=mid;
	    }
	}

	cout<<"! "<<ans<<endl;
	cout<<flush; 
}