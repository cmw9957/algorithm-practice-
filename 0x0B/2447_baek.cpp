#include<bits/stdc++.h>
using namespace std;

char box[2200][2200];

void func(int x, int y, int n){
	if(n == 1){
		box[x][y] = '*';
		return ;
	}
	int div = n/3;
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			if(i == 1 && j == 1);
			else
				func(x+(i*div), y+(j*div), div);
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
		fill(box[i], box[i] + n, ' ');
	func(0, 0, n);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cout << box[i][j];
		}
		cout << '\n';
	}
	return 0;
}
