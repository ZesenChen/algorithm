#include<iostream>

using namespace std;

bool binarysearch(float a[], float x, int begin, int end){
	int tmpb = begin, tmpe = end;
	while(tmpb <= tmpe){
		int mid = (tmpb + tmpe)/2;
		if(a[mid] == x) return true;
		else if(a[mid] < x) tmpb = mid+1;
		else tmpe = mid-1;
	}
	return false;
}

int main(){
	float a[10] = {1,2,3,4,5,6,7,8,9,10};
	cout << binarysearch(a,13,0,9) << endl;
	return 0;
} 
