/*
https://leetcode.com/problems/count-primes/
*/
#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> v_i;

int countPrimes(int n) {
    v_i isPrime(n,true);
    int cnt=0;
    for(int i=2;i<n;++i){
        if(isPrime[i]){
        	cnt++;
            for(int j=2*i;j<n;j+=i){
                isPrime[j]=0;
            }
        }
    }
    return cnt;        
}
int main(){
	int n=10;
	cout<<countPrimes(n)<<endl;
}