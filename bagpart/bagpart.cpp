#include<iostream>
#include<algorithm>

using namespace std;

struct thing{
	int v;
	int w;
	float pv;
};

int cmp(struct thing a, struct thing b){
	return a.pv > b.pv;
}

float maxValue(int v[], int w[], int N, int M){
	struct thing *th = new struct thing[N];
	float value = 0;
	int m = M;
	for(int i = 0; i < N; ++ i){
		th[i].v = v[i];
		th[i].w = w[i];
		th[i].pv = v[i]*1.0/w[i];
	}
	sort(th,th+N,cmp);
	for(int i = 0; i < N; ++ i){
		if(th[i].w < m){
			value += th[i].v;
			m -= th[i].w;
		}
		else{
			float num = m*1.0/th[i].w;
			value += num*th[i].v;
			break;
		}
	}
	return value;
}

int main(){
	int w[5] = {4,3,2,1,5};
	int v[5] = {1,2,3,4,5};
	cout << maxValue(v,w,5,10) << endl;
	return 0;
}
