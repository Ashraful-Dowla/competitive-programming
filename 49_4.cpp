/*
https://www.hackerearth.com/problem/algorithm/too-lazy-to-name-the-question-ii/
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;

int main(){
	int n;
	cin>>n;
	vector<pr>vec;
	set<pr>st;

	for(int i=0;i<n;++i){
		int x,y;
		cin>>x>>y;
		vec.push_back({x,y});
		st.insert({x,y});
	}

	vector<int>sol;
	for(int i=0;i<n;++i){
		int x1 = vec[i].first;
		int y1 = vec[i].second;
		for(int j=i+1;j<n;++j){
			int x2 = vec[j].first;
			int y2 = vec[j].second;

			auto it1 = st.find({x1,y2}); 
			auto it2 = st.find({x2,y1}); 

			if(x1==x2 || y1==y2 || it1==st.end() || it2==st.end()){
				 continue;
			}
			
			int result = abs(x2-x1)*abs(y1-y2);
			sol.push_back(result);
		}
	}

	sort(sol.begin(),sol.end());
	if(sol.size()==0) cout<<"-1"<<endl;
	else if(sol.size()==1) cout<<sol[0]<<endl;
	else cout<<sol[sol.size()-1]-sol[0]<<endl;
}