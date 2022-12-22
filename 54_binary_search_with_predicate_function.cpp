/*
https://www.spoj.com/problems/AGGRCOW/
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,cows;
int position[N];

bool can_place_cows(int min_distance){
	int last_postion = -1;
	int cows_ct=cows;

	for(int i=0;i<n;++i){
		if(position[i]-last_postion>=min_distance || last_postion==-1){
			last_postion=position[i];
			cows_ct--;
		}
	}

	return cows_ct==0;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>cows;
		for(int i=0;i<n;++i){
			cin>>position[i];
		}

		sort(position,position+n);

		int lo=0,hi=1e9,mid;

		while(hi-lo>1){
			mid = (hi+lo)/2;
			if(can_place_cows(mid)) lo=mid;
			else hi=mid-1;
		}

		if(can_place_cows(hi)) cout<<hi<<endl;
		else cout<<lo<<endl;
	}
}