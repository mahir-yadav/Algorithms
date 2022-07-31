#include<stdio.h>
void maxheap(int a[],int n){
	int temp=a[n];
	int i=n;
	while(i>0 && temp>a[(i-1)/2]){
		a[i]=a[(i-1)/2];
		i=(i-1)/2;
	}
	a[i]=temp;
}
void minheap(int a[],int n){
	int temp=a[n];
	int i=n;
	while(i>0 && temp<a[(i-1)/2]){
		a[i]=a[(i-1)/2];
		i=(i-1)/2;
	}
	a[i]=temp;
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	int i;
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		maxheap(arr,i);
	}for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}

}
