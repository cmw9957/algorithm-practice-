#include<bits/stdc++.h>
using namespace std;
int box[70][70];
void func(int x, int y, int n){
	if(n == 1){
		cout << box[x][y];
		return;
	}
	int one_cnt = 0;
	for(int i = x;i < x+n;i++){				//처음의 접근은 아주 좋았다. 다만 위치에 따라 다른 범위에 고려를 잘 하지 못했다. 
		for(int j = y;j < y+n;j++){
			if(box[i][j] == 1)
				one_cnt++;
		}
	}
	int div = n/2;
	if(!one_cnt)
		cout << 0;
	else if(one_cnt == n*n)
		cout << 1;
	else{
		cout << '(';
		func(x, y, div);
		func(x, y+div, div);
		func(x+div, y, div);
		func(x+div, y+div, div);
		cout << ')';
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	char c;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin >> c;
			box[i][j] = c-'0';
		}
	}
	func(0, 0, n);
	return 0;
}
