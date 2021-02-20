#include<bits/stdc++.h>
using namespace std;
int n, m;
int cur_x, cur_y, dir;
int box[50][50];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool check_cnnot_clean(int x, int y){
	int cnt = 0;
	for(int i = 0;i < 4;i++){
		int cx = x + dx[i];
		int cy = y + dy[i];
		if(box[cx][cy] != 0) cnt++;
	}
	if(cnt == 4) return true;
	return false;
}

void func(int x, int y, int dir){
	if(box[x][y] == 0) box[x][y] = 2;
	if(check_cnnot_clean(x, y)){
		if(dir == 0){
			if(box[x+1][y] == 1) return ;
			func(x+1, y, dir);
		}
		else if(dir == 1){
			if(box[x][y-1] == 1) return ;
			func(x, y-1, dir);
		}
		else if(dir == 2){
			if(box[x-1][y] == 1) return ;
			func(x-1, y, dir);
		}
		else{
			if(box[x][y+1] == 1) return ;
			func(x, y+1, dir);
		}
		return ;
	}
	
	if(dir == 0){
		if(box[x][y-1] == 0)
			func(x, y-1, 3);
		else
			func(x, y, 3);
	}
	else if(dir == 1){
		if(box[x-1][y] == 0)
			func(x-1, y, 0);
		else
			func(x, y, 0);
		
	}
	else if(dir == 2){
		if(box[x][y+1] == 0)
			func(x, y+1, 1);
		else
			func(x, y, 1);
	}
	else{
		if(box[x+1][y] == 0)
			func(x+1, y, 2);
		else
			func(x, y, 2);
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> cur_x >> cur_y >> dir;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> box[i][j];
	
	func(cur_x, cur_y, dir);
	int cnt = 0;
	
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			if(box[i][j] == 2) cnt++;
	
	cout << cnt;
	return 0;
}
