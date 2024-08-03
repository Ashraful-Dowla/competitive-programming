//Author: Ashraful Dowla

#include<bits/stdc++.h>
using namespace std;


void FunctionR(int A[], int a, int b) {

	if (a < b) {
		return ;
	}

	printf("%d-", A[1] + A[3]);
	A[2] = A[4];

	FunctionR(A, A[1], A[3]);

}

int main() {

	int A[] = {848, 123, 687, 981, 532};

	FunctionR(A, A[2], A[4]);
}