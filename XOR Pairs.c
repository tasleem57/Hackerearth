#include <stdio.h>
 
int main(){
	int num;
	scanf("%d", &num);              	                  // Reading input from STDIN
	int n;
	for(int i=0; i < num; i++){
		long long total = 0;
		scanf("%d", &n);
		int a[n];
		for(int j=0; j < n; j++){
			scanf("%d", &a[j]);
		}
		for(int k=0; k<n; k++){
			a[k] = a[k] ^ (k + 1);
		}
 
		mergeSort(a, 0, n-1);
		int k = 0;
		while(k < n - 1){
			long count = 0;
			while(k + count + 1 < n && a[k] == a[k + count + 1]){
				count++;
			}
			k += count + 1;
			if(count > 1){
				if (count % 2 == 0){
					total += (1 + count) * (count / 2);
				}
				else
					total += count * (count / 2) + count;
			}
			else
				total += count;
 
		}
		printf("%lu\n", total);       // Writing output to STDOUT
 
	}
}
 
// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
 
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;
 
  int L[n1], M[n2];
 
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];
 
  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;
 
  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
 
  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
 
  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}
 
// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
 
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;
 
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
 
    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}
