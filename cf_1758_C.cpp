/*
https://codeforces.com/contest/1758/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int N=2e5+10;
int arr[N];
int hp[N];
bool taken[N],isPrime[N];

void precompute(){
	memset(isPrime,true,sizeof(isPrime));
	for(int i=2;i<N;++i){
		if(isPrime[i]){
			hp[i]=i;
			for(int j=2*i;j<N;j+=i){
				isPrime[j]=false;
				hp[j]=i;
			}
		}
	}
}

vi prime_factor(int num){
	vi pf;
	while(num>1){
		int val = hp[num];
		while(num%val==0){
			num/=val;
			pf.push_back(val);
		}
	}

	sort(pf.begin(),pf.end());
	return pf;
}

void solve(){
	int n,x;
	cin>>n>>x;

	if(n%x!=0){
		cout<<-1<<endl;
		return ;
	}


	vi res = prime_factor(n/x);
	memset(taken,false,sizeof(taken));

	arr[1]=x,arr[n]=1;
	taken[1]=taken[n]=true;

	int k=x;
	for(int i=0;i<res.size();++i){
		arr[k]=res[i]*k;
		taken[k]=true;
		k=arr[k];
	}

	for(int i=1;i<=n;++i){
		if(taken[i]) cout<<arr[i]<<" ";
		else cout<<i<<" ";
	}
	cout<<endl;
}

int main(){
	int t;
	cin>>t;
	
	precompute();
	while(t--) {
	   solve();
	}
}