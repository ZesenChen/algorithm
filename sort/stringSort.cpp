#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int cmp1(string a, string b){
	return a.compare(b) < 0;
}

int cmp2(string a, string b){
	return a.size() < b.size();
}

int cmp3(string a, string b){
	string ab = a + b, ba = b + a;
	return ab.compare(ba) < 0;
}

void Cout(vector<string> A){
	for(int i = 0; i < A.size()-1; ++ i)
		cout << A[i] << " ";
	cout << A[A.size()-1] << endl;
}

//把数字串拼接成最小的数字 
string maxNum(vector<string> A){
	string tmp = "";
	sort(A.begin(),A.end(),cmp3);
	for(int i = 0; i < A.size(); ++ i){
		tmp += A[i];
	} 
	return tmp;
}

//字典排序 
void lexicographic(vector<string> A){
	sort(A.begin(),A.end(),cmp1);
	Cout(A);
}

//长度排序
void lenSort(vector<string> A){
	sort(A.begin(), A.end(), cmp2);
	Cout(A);
} 

int main(){
	string str[10] = {"126667","3221","123","214","4321","1121","155","789","15","5321"};
	vector<string> A(str,str+10);
	cout << maxNum(A) << endl;
	lexicographic(A);
	lenSort(A);
	return 0;
} 
