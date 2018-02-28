#include<iostream>

using namespace std;

int movecard(int card[], int n){
	int sum = 0, time = 0;
	for(int i = 0; i < n; ++ i){
		sum += card[i];
	}
	int avg = sum/n;
	for(int i = 0; i < n; ++ i){
		if(card[i] != avg){
			++ time;
			card[i+1] -= card[i] - avg;
			card[i] = avg;
		}
	}
	return time;
}

int main(){
	int A[4] = {1,2,4,5};
	cout << movecard(A, 4) << endl;
	return 0;
}
