#include <bits/stdc++.h>
using namespace std;

int n;
vector<int>permutation;
vector<vector<int>>permutations;
bool chosen[100];

void generate(){
	if(permutation.size()==n){
		permutations.push_back(permutation);
		return ;
	}
	for(int i=1;i<=n;++i){
		if(chosen[i]) continue;

		chosen[i]=true;
		permutation.push_back(i);
		generate();

		permutation.pop_back();
		chosen[i]=false;

	}
}

int main(){
	cin>>n;

	generate();

	for(auto &permute: permutations){
		for(int el: permute){
			cout<<el<<" ";
		}
		cout<<endl;
	}

	cout<<"-----------"<<endl;

	//built-in permutation in c++ 
	for(int i=1;i<=n;++i){
		permutation.push_back(i);
	}

	do{
		for(int el: permutation){
			cout<<el<<" ";
		}
		cout<<endl;
	}while(next_permutation(permutation.begin(),permutation.end()));
}