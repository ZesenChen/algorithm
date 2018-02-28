#include<iostream>

using namespace std;

int lis(int A[], int n){
	int dp[n];
	int max_value = 0;
	for(int i = 0; i < n; ++ i){
		dp[i] = 1;
		for(int j = 0; j < i; ++ j){
			if(A[j]<A[i]) dp[i] = max(dp[i],dp[j]+1);
		}
		max_value = max(max_value, dp[i]);
	}
	return max_value;
}

int main(){
	int A[4] = {3,2,4,5};
	cout << lis(A, 4) << endl;
	return 0;
} 
