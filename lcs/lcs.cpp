#include<iostream>

using namespace std;

int lcs(int A[], int N, int B[], int M){
	int max_value = 0;
	int dp[N][M];
	for(int i = 0; i < N; ++ i){
		for(int j = 0; j < M; ++ j){
			dp[i][j] = 0;
		}
	}
	if(A[0] == B[0]) dp[0][0] = 1;
	for(int i = 1; i < N; ++ i){
		if(dp[i-1][0] || A[i] == B[0]) dp[i][0] = 1;
	} 
	for(int j = 1; j < M; ++ j){
		if(dp[0][j-1] || A[0] == B[j]) dp[0][j] = 1;
	}
	for(int i = 1; i < N; ++ i){
		for(int j = 1; j < M; ++ j){
			if(A[i] == B[j]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j],dp[i][j-1]));
			max_value = max(max_value, dp[i][j]);
		}
	}
	return max_value;
}

int main(){
	int A[5] = {1,2,3,4,5};
	int B[6] = {2,3,4,5,6,7};
	cout << lcs(A,5,B,6) << endl;
	return 0;
} 
