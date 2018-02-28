#include<iostream>

using namespace std;

void merge(float a[], int left, int mid, int right){
	int i = left, j = mid+1;
	int k = 0;
	float *tmp = new float[right-left+1];
	while(i <= mid && j <= right){
		if(a[i] > a[j]){
			tmp[k++] = a[j++];
		}
		if(a[j] > a[i]){
			tmp[k++] = a[i++];
		}
	}
	while(i <= mid){
		tmp[k++] = a[i++];
	}
	while(j <= right){
		tmp[k++] = a[j++];
	}
	for(int i = left; i <= right; ++ i){
		a[i] = tmp[i-left];
	}
}

void mergesort(float a[], int begin, int end){
	int mid = (begin + end)/2;
	if(begin < end){
		mergesort(a,begin,mid);
		mergesort(a,mid+1,end);
		merge(a, begin, mid, end);
	}
}

int main(){
	float a[10] = {3,5,10,7,1,2,4,9,8,6};
	mergesort(a,0,9);
	for(int i = 0; i < 10; ++ i){
		cout << a[i] << endl;
	}
	return 0;
} 
