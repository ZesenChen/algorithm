#include<iostream>

using namespace std;

float pow(float x, int n){
	if(n==1) return x;
	else if(n%2){
		float tmp = pow(x,n/2);
		return tmp*tmp*x;
	}
	else{
		float tmp = pow(x,n/2);
		return tmp*tmp;
	}
}

int main(){
	float x = 2;
	cout << pow(x, 5) << endl;
	return 0;
}
