#include<string.h>
#include <stdio.h>
#include <stdlib.h>

int min(int i,int k){
    if(i>k)
        return k;
    return i;
}
int binomialCoeff(int n, int k)
{
	int C[k + 1];
	memset(C, 0, sizeof(C));

	C[0] = 1; // nC0 is 1

	for (int i = 1; i <= n; i++) {
		// Compute next row of pascal triangle using
		// the previous row
		for (int j = min(i, k); j > 0; j--)
			C[j] = C[j] + C[j - 1];
	}
	return C[k];
}

/* Driver code*/
int main()
{
	int n,k;
	printf("Enter value of N= ");
	scanf("%d", &n);
	printf("Enter value of K= ");
	scanf("%d", &k);
	if(k>n){
        printf("ERROR! K cannot be greater than N\n");
        exit(1);
	}
	printf("Value of C(%d, %d) is %d \n", n, k,
		binomialCoeff(n, k));
	return 0;
}
