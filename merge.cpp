#include<iostream>
void merge(int arr[],int left,int mid, int right){
	int n1=mid-left+1;
	int n2=right-mid;
	int l[n1];
	int r[n2];
	int i,j;
	for (i = 0; i < n1 ; ++i) {
		l[i]=arr[i+left];
	}
	for (j = 0; j < n2 ; ++j) {
		r[j]=arr[mid+j+1];
	}
	i=0;
	j=0;
	int k=left;
	while(i<n1 && j<n2){
		if(l[i]<=r[j]){
			arr[k]=l[i];
			++i;
		} else{
		arr[k]=r[j];
		++j;
		}
		++k;
	}
	while(i<n1){
		arr[k]=l[i];
		++i;
		++k;
	}
	while(j<n2){
		arr[k]=r[j];
		++j;
		++k;
	}
}
void merge_s(int arr[],int left,int right){
	if(left<right){
		int mid =left+(right-left)/2;
		merge_s(arr,left,mid);
		merge_s(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}
int main(){
	int arr[]={50,5,9,6,6,10,4,0,4};
	int n=sizeof(arr)/sizeof(arr[0]);
	for(int i=0; i < n; i++){
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
	merge_s(arr,0,n-1);
	for(int i=0; i < n; i++){
	std::cout<<arr[i]<<" ";
	}
}
