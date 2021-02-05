#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int box[10][10];
int box2[10][10];
vector<pair<int, int> > cctv;
int n, m;
bool chk(int a, int b){
	return a < 0 || a >= n || b < 0 || b >= m;
}

void func(int x, int y, int dir){
	dir %= 4;
	while(1){
		x += dx[dir];
		y += dy[dir];
		if(chk(x, y) || box2[x][y] == 6) return;
		if(box2[x][y] != 0) continue;
		box2[x][y] = -1;
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int total = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> box[i][j];
			if(box[i][j] != 0 && box[i][j] != 6)
				cctv.push_back({i, j});
			if(box[i][j] == 0)
				total++;
		}
	}
	
	for(int k = 0;k < (1<<(2*cctv.size()));k++){
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				box2[i][j] = box[i][j];
		int brute = k;
		for(int i = 0;i < cctv.size();i++){
			int dir = brute%4;
			brute /= 4;
			int x, y;
			tie(x, y) = cctv[i];
			if(box[x][y] == 1){
				func(x, y, dir);
			}
			else if(box[x][y] == 2){
				func(x, y, dir);
				func(x, y, dir+2);
			}
			else if(box[x][y] == 3){
				func(x, y, dir);
				func(x, y, dir+1);
			}
			else if(box[x][y] == 4){
				func(x, y, dir);
				func(x, y, dir+1);
				func(x, y, dir+2);
			}
			else if(box[x][y] == 5){
				func(x, y, dir);
				func(x, y, dir+1);
				func(x, y, dir+2);
				func(x, y, dir+3);
			}
		}
		int sum = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				sum += (box2[i][j] == 0);
			}
		}
		total = min(total, sum);
	}
	cout << total;
	return 0;
}
