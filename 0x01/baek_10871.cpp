#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int A[10000] = {0}, N, X;
	cin >> N >> X;
	for(int i = 0;i < N;i++){
		cin >> A[i];
		if(A[i] < X)
			cout << A[i] << " ";
	}
	return 0;
} 
