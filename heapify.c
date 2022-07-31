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
void delete(int a[],int n){
	int x,i,j,temp;
	x=a[0];
	a[0]=a[n-1];
	a[n-1]=x;
	i=0;
	j=2*(i)+1;
	while(j<=n-2){
		if(j<n-2 && a[j+1]>a[j]){
			j=j+1;
		}
		if(a[i]<a[j]){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i=j;
			j=(2*j+1);
		}else{
			break;
		}
	}
}
void heapify(int a[],int n){
	int temp;
	for(int i=(n/2)-1;i>=0;i--){
		int j=2*i+1;
		while(j<n-1){
			if(a[j]<a[j+1]){
				j=j+1;
			}if(a[i]<a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				i=j;
				j=2*i+1;
			}else{
				break;
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	int i;
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	heapify(arr,n);
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	delete(arr,n);
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
