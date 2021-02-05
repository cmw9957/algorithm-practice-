#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int r, c;
int box[45][45];
int post[15][15];

bool func(int x, int y){
	for(int i = 0;i < r;i++){
		for(int j = 0;j < c;j++){
			if(box[x+i][y+j] == 1 && post[i][j] == 1) return false;
		}
	}
	for(int i = 0;i < r;i++){
		for(int j = 0;j < c;j++){
			if(post[i][j] == 1) box[x+i][y+j] = 1;
		}
	}
	return true;
}

void turn(){
	int temp[15][15];
	for(int i = 0;i < r;i++){
		for(int j = 0;j < c;j++){
			temp[i][j] = post[i][j];
		}
	}
	for(int i = 0;i < c;i++){
		for(int j = 0;j < r;j++){
			post[i][j] = temp[r-1-j][i];
		}
	}
	swap(r, c);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	while(k--){
		cin >> r >> c;
		for(int i = 0;i < r;i++){
			for(int j = 0;j < c;j++){
				cin >> post[i][j];
			}
		}
		for(int k = 0;k < 4;k++){
			bool is_right = false;
			for(int x = 0;x <= n-r;x++){
				if(is_right) break;
				for(int y = 0;y <= m-c;y++){
					if(func(x, y)){//스티커 붙힐수 있고 붙혀놓은 상태 
						is_right = true;
						break;
					}
				}
			}
			if(is_right) break;
			turn();
		}
	}
	int cnt = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cnt += box[i][j];
	cout << cnt;
	return 0;
}
