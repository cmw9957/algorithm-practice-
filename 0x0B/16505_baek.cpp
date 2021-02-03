#include<bits/stdc++.h>
using namespace std;
char box[1300][1300];
void func(int x, int y, int n){
	if(n == 1){
		box[x][y] = '*';
		return ;
	}
	int div = n/2;
	func(x, y, div);
	func(x+div, y, div);
	func(x, y+div, div);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	n = 1 << n;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			box[i][j] = ' ';
		}
	}
	func(0, 0, n);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n - i;j++){
			cout << box[i][j];
		}
		cout << '\n';
	}
	return 0;
}
