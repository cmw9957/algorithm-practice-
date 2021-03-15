#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, m;
int lx, ly;
bool connect;
string box[1505];
bool vis[1505][1505];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void is_connect(){
	queue<pair<int, int> > Q;
	Q.push({lx, ly});
	vis[lx][ly] = true;
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for(int dir = 0;dir < 4;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(vis[nx][ny] || box[nx][ny] == 'X') continue;
			if(box[nx][ny] == 'L'){
				connect = true;
				return ;
			}
			vis[nx][ny] = true;
			Q.push({nx, ny});
		}
	}
	for(int i = 0;i < n;i++)
		fill(vis[i], vis[i]+m, false);
}

void melting_ice(){
	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(box[i][j] == 'X' && !vis[i][j]){
				queue<pair<int, int> > Q;
				vis[i][j] = true;
				Q.push({i, j});
				while(!Q.empty()){
					auto cur = Q.front(); Q.pop();
					for(int dir = 0;dir < 4;dir++){
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if(vis[nx][ny]) continue;
						if(box[nx][ny] != 'X'){
							box[cur.X][cur.Y] = '.';
							continue;
						}
						vis[nx][ny] = true;
						Q.push({nx, ny});
					}
				}
			}
		}
	}
	for(int i = 0;i < n;i++)
		fill(vis[i], vis[i]+m, false);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 0;i < n;i++)
		cin >> box[i];
	bool fd = false;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(box[i][j] == 'L'){
				lx = i;
				ly = j;
				fd = true;
				break;
			}
		}
		if(fd) break;
	}
	
	for(int i = 0;;i++){
		is_connect();
		if(connect){
			cout << i;
			return 0;
		}
		melting_ice();
	}
	return 0;
}
