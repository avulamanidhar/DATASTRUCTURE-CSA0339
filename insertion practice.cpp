#include<stdio.h>
void insertionsort(int arr[],int n){
	int i,j,key;
	for(i=1;i<n;i++){
		key=arr[i];
		j=i-1;
		while(j>=0&&arr[j]>key){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
			}
}
void displayarray(int arr[],int n){
	printf("sorted array:");
	for(int i=0;i<n;i++){
		printf("%d",arr[i]);
	}
	printf("\n");
}
int main(){
	int n;
	printf("enter the no.of elements");
	scanf("%d",&n);
	int arr[n];
	printf("enter %d elements",n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	insertionsort(arr,n);
	displayarray(arr,n);
	return 0;
}
