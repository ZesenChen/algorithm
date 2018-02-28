#include<iostream>
#include<vector>

using namespace std;

//¶ş·Ö²éÕÒ 

int binarySearch(vector<int> A, int target){
	int left = 0, right = A.size()-1;
	int mid;
	while(left <= right){
		mid = (left+right)/2;
		if(target == A[mid]) return mid;
		else if(target < A[mid]) right = mid - 1;
		else left = mid + 1;
	} 
	return -1;
}

int main(){
	int num[11] = {1,3,5,7,9,12,21,32,90,190,210};
	vector<int> A(num,num+11);
	cout << binarySearch(A, 22) << endl;
	return 0;
}
