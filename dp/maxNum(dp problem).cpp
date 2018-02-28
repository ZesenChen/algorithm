#include<iostream>
#include<vector>

using namespace std;

int maxNum(int A[], int N, int K){
	vector<vector<int> > dp(N+1, vector<int>(K+1, 0));
	vector<int> sum(N, 0);
	sum[0] = A[0];
	for(int i = 0; i < N; ++ i){
		sum[i] = sum[i-1] + A[i];
	}
	for(int i = 0; i <= N; ++ i){
		dp[i][0] = sum[i];
	}
	for(int i = 2; i <= N; ++ i){
		int t = min(i-1, K);
		for(int j = 1; j <= K; ++ j){
			for(int K = 2; K <= i; ++ K){
				int s = sum[i] - sum[K-1];
				dp[i][j] = max(dp[K-1][j-1]*s, dp[i][j]);
			}
		}
	}
	return dp[N][K];
}

#define MAX_NUM 1000000

int subMaxNumSum(int A[], int N, int B){
	int fuck = 0;
	vector<vector<int> > MAX(N, vector<int>(N, 0));
	vector<vector<int> > SUM(N, vector<int>(N, 0));
	vector<vector<int> > SUB(N, vector<int>(N, 0));
	for(int i = 0; i < N; ++ i){
		int tmp = 0;
		int sum = 0;
		for(int j = i; j < N; ++ j){
			tmp = max(A[j], tmp);
			sum += A[j];
			MAX[i][j] = tmp;
			SUM[i][j] = sum;
			if(sum <= B) SUB[i][j] = MAX[i][j];
			else SUB[i][j] = MAX_NUM;
		}
	}
	for(int x = 0; x < N; ++ x){
		for(int i = 0; i < N-x; ++ i){
			int j = i + x;
			int tmp = MAX_NUM;
			for(int k = i; k < j; ++ k){
				tmp = min(tmp, SUB[i][k]+SUB[k+1][j]);
			}
			SUB[i][j] = min(SUB[i][j], tmp); 
		}
	} 
	return SUB[0][N-1];
}

__int64 dp[20][20];
int sum[20][20];
int a[20];

int main(){
	
} 
