#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>

using namespace std;

int cmp(string a, string b){
	return (a+b).compare(b+a) > 0;
}
string num2str(int i)
{
        stringstream ss;
        ss<<i;
        return ss.str();
}

string largestlongnum(int A[], int n){
	string str[n] = {""}, lnum = "";
	for(int i = 0; i < n; ++ i) str[i] = num2str(A[i]);
	sort(str,str+n,cmp);
	for(int i = 0; i < n; ++ i){
		lnum += str[i];
	}
	return lnum;
}

int main(){
	int A[5] = {432,12,121,23,90};
	cout << largestlongnum(A,5) << endl;
	return 0;
}
