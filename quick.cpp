#include<iostream>
void quick(int arr[],int left,int right){
	int pivot=arr[left+(right-left)/2];
	int l=left;
	int r=right;
	while(l<=r){
		while(arr[l]<pivot){
			l++;
	 	}
		while(arr[r]>pivot){
			r--;
		}
		if(l<=r){
			int temp;
			temp=arr[l];
			arr[l]=arr[r];
			arr[r]=temp;
			l++;
			r--;
		}
	}	
	if(left<=r){
		quick(arr,left,r);
	}
	if(l<=right){
		quick(arr,l,right);
	}
}
int main(){
	int arr[]={76,52,5,54,4,4,85,7};
	quick(arr,0,7);
	int n= sizeof(arr)/ sizeof(arr[0]);
	for (int i = 0; i < n ; ++i) {
		std::cout<<arr[i]<<" ";
	}
}
