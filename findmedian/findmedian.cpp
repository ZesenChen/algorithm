#include<iostream>
#include<math.h> 

using namespace std;

float findmedian(int X[], int Y[], int startX, int endX, int startY, int endY){
	if(endX<=startX) 
		return (X[startX]+Y[endY])*1.0/2;
	int midX = (startX+endX)/2, midY = ceil((startY+endY)*1.0/2);
	if(X[midX]==Y[midY]) 
		return X[midX];
	else if(X[midX]<Y[midY]) 
		return findmedian(X,Y,midX+1,endX,startY,midY-1);
	else 
		return findmedian(X,Y,startX,midX-1,midY+1,endY);
}

int main(){
	int Y[15] = {1,2,3,4,5,6,7,8,9,10};
	int X[15] = {11,12,13,14,15,16,17,18,19,20};
	cout << findmedian(X,Y,0,9,0,9) << endl;
	//cout << ceil(10) << endl;
	return 0;
}
