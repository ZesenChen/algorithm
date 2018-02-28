#include<iostream>
#include<algorithm>

using namespace std;

int gasstation(int dis[], int k, int N, int L){
	if(N > L) return 0;//汽车的油足够开到B城市 
	int sum = 0, length = N, tmp = 0;
	sort(dis, dis+k);
	if(dis[0] > N) return -1;//汽车的油不够开到最近的加油站 
	for(int i  = 0; i < k; ++ i){
		if(dis[i] > length){
			++ sum;
			length = dis[i-1] + N;
		}
	}
	if(length < L) ++ sum;
	return sum;
}

int main(){
	int A[6] = {6,5,4,3,2,1};
	cout << gasstation(A, 6, 2, 7) << endl;
	return 0;
}
