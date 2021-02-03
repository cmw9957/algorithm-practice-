#include<bits/stdc++.h>
using namespace std;

int box[2200][2200];
int cnt[3];
void func(int x, int y, int n){
	if(n == 1){
		int num = box[x][y];
		if(num < 0) cnt[2]++;
		else cnt[num]++;
		return;
	}
	int one_cnt = 0; int zero_cnt = 0; int minus_cnt = 0;
	for(int i = x;i < x+n;i++){
		for(int j = y;j < y+n;j++){
			if(box[i][j] == 1) one_cnt++;
			else if(box[i][j] == 0) zero_cnt++;
			else if(box[i][j] == -1) minus_cnt++;
		}
	}
	int div = n/3;
	if(one_cnt == n*n) cnt[1]++;
	else if(zero_cnt == n*n) cnt[0]++;
	else if(minus_cnt == n*n) cnt[2]++;
	else{
		func(x, y, div);
		func(x, y+div, div);
		func(x, y+div*2, div);
		func(x+div, y, div);
		func(x+div, y+div, div);
		func(x+div, y+div*2, div);
		func(x+div*2, y, div);
		func(x+div*2, y+div, div);
		func(x+div*2, y+div*2, div);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin >> box[i][j];
		}
	}
	func(0, 0, n);
	cout << cnt[2] << '\n' << cnt[0] << '\n' << cnt[1];
}
