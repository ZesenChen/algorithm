#include<iostream>

using namespace std;

/*����һ��СΪn,��С�����ź��������,�������е�Ԫ��ѭ��������kλ*/

int findmaxnum(int A[], int start, int end){
	if(end <= start) return A[start];
	int mid = (start+end)/2;
	if(A[end]>A[mid] && A[end]>A[start]) 
		return A[end];
	else if(A[mid]<A[start] && A[mid]<A[end])
		return findmaxnum(A,start,mid-1);
	else if(A[mid]>A[start] && A[mid]>A[end])
		return findmaxnum(A,mid,end); 
}

int main(){
	int A[10] = {10,11,12,13,14,1,6,7,8,9};
	cout << findmaxnum(A,0,9) << endl;
	return 0;
} 
