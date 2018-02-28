#include<iostream>
#include<vector>
#include<sstream>
#include<string> 
using namespace std;

//最长上升子序列 
int LIS(int a[], int n){
	vector<int> dp(n,1);
	for(int i = 1; i < n; ++ i){
		for(int j = 0; j < i; ++ j){
			if(a[j]<a[i])  dp[i] = max(dp[j]+1,dp[i]);
		}
	}
	return dp[n-1];
}

int main(){
    int a[5] = {2,4,1,5,6};
    cout << LIS(a,5) << endl; 
    return 0;
}
