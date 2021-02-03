#include<iostream>
using namespace std;
int func(int n, int r, int c){
	if(n == 0) return 0;
	int half = (1<<n-1);											//사각형을 반씩 잘라 구역을 나누기위해
	if(r < half && c < half) return func(n-1, r, c);
	if(r >= half && c < half) return 2*half*half + func(n-1, r, c);
	if(r < half && c >= half) return half*half + func(n-1, r, c);
	return 3*half*half + func(n-1, r, c);
} 

int main(){
	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);
}
