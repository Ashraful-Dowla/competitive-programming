#include <bits/stdc++.h>
using namespace std;

string generate(char ch,int n){
	string s="";
	for(int i=0;i<n;++i){
		s.push_back(ch);
	}
	return s;
}

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int n1,n2;
	    string str;
	    if(n==1) cout<<'a'<<endl;
	    else {
			if(n%2==0){
		    	n--;
		    	n1 = n/2;
		    	n2 =  n-n1;
		    	str = generate('a',n1);
		    	str.push_back('b');
		    	str+=generate('a',n2);
		    }
		    else {
		    	n-=2;
		    	n1 = n/2;
		    	n2 = n-n1;
		    	str = generate('a',n1);
		    	str+="bc";
		    	str+=generate('a',n2);
		    }
		    cout<<str<<endl;
	    }
	}
}