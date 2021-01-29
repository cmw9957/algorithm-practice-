#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char box[102][102];
bool vis[102][102];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n;

int bfs(){
	int cnt = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(!vis[i][j]){
				cnt++;
				vis[i][j] = 1;
				queue<pair<int, int> > Q;
				Q.push({i, j});
				while(!Q.empty()){
					auto cur = Q.front(); Q.pop();
					for(int dir = 0;dir < 4;dir++){
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if(box[nx][ny] != box[cur.X][cur.Y] || vis[nx][ny]) continue;
						vis[nx][ny] = 1;
						Q.push({nx, ny});
					}
				}
			}
		}
	}
	
	return cnt;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++)
			cin >> box[i][j];
	}
	
	cout << bfs() << ' ';
	
	for(int i = 0;i < n;i++)
		fill(vis[i], vis[i] + n, 0);
		
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(box[i][j] == 'G')
				box[i][j] = 'R';
		}
	}
	
	cout << bfs();
	return 0;
}
