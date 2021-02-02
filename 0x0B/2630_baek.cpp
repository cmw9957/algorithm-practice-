#include<iostream>
using namespace std;

int box[130][130];
int white_cnt;
int blue_cnt;

void func(int x, int y, int n){
	int temp_cnt = 0;
	for(int i = x;i < x + n;i++){
		for(int j = y;j < y + n;j++){
			if(box[i][j]) temp_cnt++;
		}
	}
	if(!temp_cnt) white_cnt++;
	else if(temp_cnt == n*n) blue_cnt++;
	else{
		func(x, y, n/2);
		func(x, y+n/2, n/2);
		func(x+n/2, y, n/2);
		func(x+n/2, y+n/2, n/2);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++) cin >> box[i][j];
	func(0, 0, n); cout << white_cnt << '\n' << blue_cnt;
}
