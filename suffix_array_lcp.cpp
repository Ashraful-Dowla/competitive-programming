#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;

const int MAX_N=1e5+10;
char T[MAX_N];
int n;
int RA[MAX_N],tempRA[MAX_N];
int SA[MAX_N],tempSA[MAX_N];
int c[MAX_N];
int LCP[MAX_N],PLCP[MAX_N],Phi[MAX_N];

//time complexity -> O(n^2)
void computeLCP_slow(){
	LCP[0]=0;
	for(int i=1;i<n;++i){
		int L=0;
		while(T[SA[i]+L]==T[SA[i-1]+L]) L++;
		LCP[i]=L;
	}

	for(int i=0;i<n;++i){
		cout<<LCP[i]<<" ";
	}
	cout<<endl;
}

//time complexity -> O(n)
void computeLCP(){
	PLCP[SA[0]]=-1;
	for(int i=1;i<n;++i){
		Phi[SA[i]]=SA[i-1];
	}

	for(int i=0,L=0;i<n;++i){
		if(Phi[i]==-1){
			PLCP[i]=0;
			continue;
		}
		while(T[i+L]==T[Phi[i]+L]) L++;
		PLCP[i]=L;
		L=max(L-1,0);
	}

	for(int i=0;i<n;++i){
		LCP[i]=PLCP[SA[i]];
		cout<<LCP[i]<<" ";
	}
	cout<<endl;
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

	computeLCP_slow();
	computeLCP();
}