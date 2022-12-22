#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int attack[n+5];
		int done[n+5];
		memset(attack,0,sizeof(attack));
		memset(done,false,sizeof(done));
		for(int i=0;i<n;++i){
			int idx;
			if(s[i]=='L') idx = i-1<0 ? n-1 : i-1 ;
			else idx = i==n-1 ? 0 : i+1 ;

			attack[idx]++;
		}
		int cnt=0;
		for(int i=0;i<n;++i){
			// cout<<i<<" "<<attack[i]<<endl;
			int idx;
			if(s[i]=='L') idx = i-1<0 ? n-1 : i-1 ;
			else idx = i==n-1 ? 0 : i+1 ;

			if(attack[i]==2 || attack[idx]==2|| done[i]) continue;
			else if(attack[i]==1 && attack[idx]==1 && s[i]!=s[idx]){
				continue;
			}
			else if(attack[i]==0 && attack[idx]==1){
				attack[i]=1;
				done[i]=done[idx]=true;
				s[idx] = (s[idx] == 'L' ? 'R' : s[idx]);
				cnt++;
			}
			else if(attack[i]==1 && attack[idx]==1 && s[i]==s[idx]){
				done[i]=done[idx]=true;
				s[idx] = (s[idx] == 'L' ? 'R' : s[idx]);
				cnt++;
			}
		}
		// cout<<s<<endl;
		cout<<cnt<<endl;
	}
}