/*
https://codeforces.com/contest/1777/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int INF=1e9+10;
vector<int> divisors[N];

void precompute(){
	for(int i=1;i<N;++i){
		divisors[i].push_back(1);
		for(int j=i;j<N;j+=i){
			divisors[j].push_back(i);
		}
	}
}

void solve(){
	int n,m;
	scanf("%d %d", &n,&m);

	vector<int> vec;
	for(int i=0;i<n;++i){
		int x;
		scanf("%d", &x);
		vec.push_back(x);
	}

	int cnt[N+5];
	memset(cnt,0,sizeof(cnt));


	sort(vec.begin(),vec.end());	
	int j=0, freq=0,ans=INF;

	for(int i=0;i<n;++i){
		for(auto val: divisors[vec[i]]){
			if(val>m) break;
			if(cnt[val]==0){
				freq++;
			}
			cnt[val]++;
		}

		while(freq==m){
			ans = min(ans, vec[i]-vec[j]);
			
			for(auto val: divisors[vec[j]]){
				if(val>m) break;
				cnt[val]--;
				if(cnt[val]==0){
					freq--;
				}
			}
			++j;
		}

	}
	ans = ans == INF ? -1 : ans;
	printf("%d\n",ans);
}

int main(){
	int t;
	scanf("%d", &t);

	precompute();

	while(t--) {
	    solve();
	}
}