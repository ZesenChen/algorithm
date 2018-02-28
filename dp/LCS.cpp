#include<iostream>
#include<string>
#include<vector>

using namespace std;

//最长公共子序列 
int LCS(string a, string b){
	vector<vector<int> > maxSub(a.size(),vector<int>(b.size(),0));
	maxSub[0][0] = a[0]==b[0]?1:0;
	for(int i = 1; i < a.size(); ++ i){
		maxSub[i][0] = a[i]==b[0]?1:maxSub[i-1][0];
	}
	for(int j = 1; j < b.size(); ++ j){
		maxSub[0][j] = b[j]==a[0]?1:maxSub[0][j-1];
	}
	for(int i = 1; i < a.size(); ++ i){
		for(int j = 1; j < b.size(); ++ j){
			if(a[i] == b[j]) maxSub[i][j] = maxSub[i-1][j-1] + 1;
			else maxSub[i][j] = max(maxSub[i-1][j], maxSub[i][j-1]);
		}
	}
	return maxSub[a.size()-1][b.size()-1];
}

int main(){
	string a = "fuckyou", b = "youfuck";
	cout << LCS(a,b) << endl;
	return 0;
} 
