#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;

const int MAX_N=1e5+10;
char T[MAX_N],P[MAX_N];
int n,m;
int RA[MAX_N],tempRA[MAX_N];
int SA[MAX_N],tempSA[MAX_N];
int c[MAX_N];


pr stringMatching(){
	int lo=0,hi=n-1,mid=lo;
	while(lo<hi) {
	   mid=(lo+hi)/2;
	   int res = strncmp(T+SA[mid],P,m);
	   if(res>=0) hi=mid;
	   else lo = mid+1; 
	}

	if(strncmp(T+SA[lo],P,m)!=0) return {-1,-1};

	pr ans;
	ans.first=lo;

	lo=0,hi=n-1,mid=lo;
	while(lo<hi) {
	   mid=(lo+hi)/2;
	   int res = strncmp(T+SA[mid],P,m);
	   if(res>0) hi=mid;
	   else lo = mid+1; 
	}

	if(strncmp(T+SA[hi],P,m)!=0) hi--;
	ans.second = hi;

	return ans;
}

//time complexity->O(n)
void countingSort(int k){
	int maxi=max(300,n);
	memset(c,0,sizeof(c));

	//counting based on rank
	for(int i=0;i<n;++i){
		c[i+k<n ? RA[i+k]: 0]++;
	}

	//prefix sum array
	for(int i=0,sum=0;i<maxi;++i){
		int t=c[i];
		c[i]=sum;
		sum+=t;
	}

	for(int i=0;i<n;++i){
		tempSA[c[SA[i]+k<n ? RA[SA[i]+k]:0]++]=SA[i];
	}

	for(int i=0;i<n;++i){
		SA[i]=tempSA[i];
	}
}

// time complexity->O(nlogn)
void constructSA(){
	int i,k,r;
	for(int i=0;i<n;++i){
		RA[i]=T[i];
		SA[i]=i;
	}

	for(int k=1;k<n;k<<=1){
		countingSort(k);
		countingSort(0);
		tempSA[SA[0]]=r=0;

		for(int i=1;i<n;++i){
			if(RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k]){
				tempRA[SA[i]]=r;
			}
			else tempRA[SA[i]]=++r;
		}

		for(int i=0;i<n;++i){
			RA[i]=tempRA[i];
		}
	}
}

int main(){	
	n=(int)strlen(gets(T));
	T[n++]='$';
	constructSA();
	for(int i=0;i<n;++i){
		cout<<SA[i]<<" "<<T+SA[i]<<endl;
	}

	m=(int)strlen(gets(P));
	pr pos = stringMatching();

	if(pos.first!=-1 && pos.second!=-1) {
		cout<<pos.first<<" "<<pos.second<<endl;
		for(int i=pos.first;i<=pos.second;++i){
			cout<<T+SA[i]<<endl;
		}
	}

}