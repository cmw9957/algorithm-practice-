#include<bits/stdc++.h>
using namespace std;
int box[205][205];
int vis[205][205][2];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int jx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int jy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, n, m;
	cin >> k >> m >> n;
	
	if(m == 1 && n == 1){
		cout << 0;
		return 0;
	}
	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> box[i][j];
		}
	}
	
	queue<tuple<int, int, int> > Q;
	Q.push(make_tuple(0, 0, 0));
	vis[0][0][0] = 1;
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		int x, y, jmp, at = 0;
		tie(x, y, jmp) = cur;
		if(jmp) at = 1;
		for(int dir = 0;dir < 4;dir++){
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if(nx == n-1 && ny == m-1){
				cout << vis[x][y][at];
				return 0;
			}
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(at && vis[nx][ny][0] || vis[nx][ny][at]) continue;
			if(jmp == k && box[nx][ny] == 1) continue;
			if(jmp != k && box[nx][ny] == 1){
				jmp++;
				for(int j = 0;j < 8;j++){
					int jmp_x = x + jx[j];
					int jmp_y = y + jy[j];
					if(jmp_x == n-1 && jmp_y == m-1){
						cout << vis[x][y][at];
						return 0;
					}
					if(jmp_x < 0 || jmp_x >= n || jmp_y < 0 || jmp_y >= m) continue;
					if(vis[jmp_x][jmp_y][0] || vis[jmp_x][jmp_y][1] || box[jmp_x][jmp_y] == 1) continue;
					vis[jmp_x][jmp_y][1] = vis[x][y][at] + 1;
					Q.push(make_tuple(jmp_x, jmp_y, jmp));
				}
				continue;
			}
			vis[nx][ny][at] = vis[x][y][at] + 1;
			Q.push(make_tuple(nx, ny, at));
		}
	}
	cout << -1;
	return 0;
}
