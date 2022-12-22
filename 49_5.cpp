/*
https://www.hackerearth.com/problem/algorithm/luffy-needs-food/
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k,f;
		cin>>n>>k>>f;
		vector<pr>vec;

		for(int i=0;i<n;++i){
			int x_k, fd;
			cin>>x_k>>fd;
			vec.push_back({k-x_k,fd});
		}

		sort(vec.begin(),vec.end());
		multiset<int>ms;
		int current = 0,ans=0;
		bool chk = true;

		for(int i=1;i<k;++i){
			f--;
			if(vec[current].first ==i) {
				ms.insert(vec[current].second);
				current++;
			}
			if(f==0){
				if(ms.size()==0) {
					chk = false;
					break;
				}else {
					auto it = --ms.end();
					f+=(*it);
					ans++;
					ms.erase(it);
				}
			}
		}

		cout<<(chk ? ans: -1)<<endl;
	}
}