#include<stdio.h>
#include<stdlib.h>
int maximum(int a,int b){
    return ((a>b)?a:b);
}

int minimum(int a,int b){
    return ((a<b)?a:b);
}

int max(int a[], int ub){
    if(ub==0)
        return a[0];
    else return(maximum(a[ub],max(a,ub-1)));
}

int min(int a[], int ub){
    if(ub==0)
        return(a[0]);
    else return(minimum(a[ub],min(a,ub-1)));
}


void main(){
    int a[50],n;
    printf("Enter the Number of Elements: ");
    scanf("%d",&n);
    if(n<=0){
        printf("ERROR: Invalid Input");
        exit(1);
    }
    printf("Enter the Elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&(a[i]));

    int FinalMax=max(a,n-1);
    printf("Maximum Number of the Array: %d\n",FinalMax);
    int FinalMin=min(a,n-1);
    printf("\nMinimum Number of the Array: %d\n",FinalMin);
}
