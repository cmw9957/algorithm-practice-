#include<bits/stdc++.h>
using namespace std;
int box[205][205];
bool vis[205][205][35];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int jx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int jy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, n, m;
	cin >> k >> m >> n;
	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> box[i][j];
		}
	}
	
	queue<tuple<int, int, int, int> > Q;
	Q.push(make_tuple(0, 0, k, 0));
	vis[0][0][0] = true;
	
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		int x, y, j, cnt;
		tie(x, y, j, cnt) = cur;
		
		if(x == n-1 && y == m-1){
			cout << cnt;
			return 0;
		}
		
		for(int dir = 0;dir < 4;dir++){
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(vis[nx][ny][j] || box[nx][ny]) continue;
			vis[nx][ny][j] = true;
			Q.push(make_tuple(nx, ny, j, cnt+1));
		}
		
		if(j == 0) continue;
		
		for(int dir = 0;dir < 8;dir++){
			int nx = x + jx[dir];
			int ny = y + jy[dir];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(vis[nx][ny][j-1] || box[nx][ny]) continue;
			vis[nx][ny][j-1] = true;
			Q.push(make_tuple(nx, ny, j-1, cnt+1));
		}
	}
	cout << -1;
	return 0;
}
