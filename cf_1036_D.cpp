/*
https://codeforces.com/contest/1036/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=3e5+10;
int a[N],b[N];

int main(){
	int n;
	// cin>>n;
	scanf("%d",&n);
	ll totalA=0,totalB=0;
	for(int i=0;i<n;++i){
		// cin>>a[i];
		scanf("%d",&a[i]);
		totalA+=a[i];
	}
	int m;
	// cin>>m;
	scanf("%d",&m);
	for(int i=0;i<m;++i){
		// cin>>b[i];
		scanf("%d",&b[i]);
		totalB+=b[i];
	}

	if(totalA!=totalB) {
		// cout<<-1<<endl;
		printf("-1");
		return 0;
	}

	int i=0, j=0,ans=0;
	ll sum_a=0,sum_b=0;

	while(i<n) {
		sum_a+=a[i];
		sum_b+=b[j];

		if(sum_a==sum_b){
			ans++;
			sum_a=sum_b=0;
			i++,j++;
			continue;
		}

		if(sum_a<sum_b){
			i++;
			sum_b-=b[j];
		}
		else {
			j++;
			sum_a-=a[i];
		}
	}
	printf("%d\n",ans);
}