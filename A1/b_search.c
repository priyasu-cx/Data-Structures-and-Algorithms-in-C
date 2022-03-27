#include <stdio.h>
#define MAX 1000
int bsearch(int arr[], int l, int r, int x){
  if(r>=l){
    int mid = l + (r-1)/2;
    if(arr[mid] == x)
      return mid;
    if(arr[mid] > x)
      return bsearch(arr, l, mid-1, x);
    return bsearch(arr, mid+1, r, x);
  }
  return -1;
}

int main(){
  int arr[MAX], x, n;
  printf("Enter no of elements: ");
  scanf("%d", &n);
  printf("Enter the elements in sorted order: \n");
  for(int i=0; i<n; i++)
    scanf("%d", &arr[i]);
  printf("Enter the value to search : ");
  scanf("%d", &x);
  int result = bsearch(arr, 0, n-1, x);
  (result == -1)
    ? printf("Element is not present in the array!\n")
    : printf("Element present at index %d\n", result+1);
  return 0;
}
