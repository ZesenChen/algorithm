#include<iostream>
#include<vector>

using namespace std;

int findmaxmat(vector<vector<int> > A, int n){
	vector<vector<int> > dp(n, vector<int>(n,0));
	int maxrank;
	for(int i = n-1; i >= 0; --i){
		if(A[i][n-1]==1) {
			dp[i][n-1] = 1;
			maxrank = 1;
		}
		else dp[i][n-1] = 0;
		if(A[n-1][i]==1){
			dp[n-1][i] = 1;
			maxrank = 1;
		}
		else dp[n-1][i] = 0;
	}
	for(int i = n-2; i >= 0; --i){
		for(int j = n-2; j >= 0; --j){
			if(A[i][j]==0) dp[i][j] = 0;
			else{
				dp[i][j] = min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1])) + 1;
			}
			maxrank = max(maxrank, dp[i][j]);
		}
	}
	return maxrank;
}

int main(){
	vector<vector<int> > A(6,vector<int>(6,1));
	//A[2][2] = 0;
	cout << findmaxmat(A,6) << endl;
	return 0;
}
