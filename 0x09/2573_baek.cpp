#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int box[305][305];
bool vis[305][305];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1}; 
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++)
			cin >> box[i][j];
	}
	
	//처음부터 두덩이 였을 경우 
	int right_cnt = 0;
	for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(box[i][j] && !vis[i][j]){
					right_cnt++;
					vis[i][j] = 1;
					queue<pair<int, int> > Q;
					Q.push({i, j});
					while(!Q.empty()){
						auto cur = Q.front(); Q.pop();
						for(int dir = 0;dir < 4;dir++){
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
							if(vis[nx][ny] || !box[nx][ny]) continue;
							Q.push({nx, ny});
							vis[nx][ny] = 1;
						}
					}
				}
			}
		}
	if(right_cnt >= 2){
		cout << 0 << '\n';
		return 0;
	}
	for(int i = 0;i < n;i++)
			fill(vis[i], vis[i] + m, 0);
			
	for(int v = 1;;v++){
			for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(box[i][j] && !vis[i][j]){
					vis[i][j] = 1;
					queue<pair<int, int> > Q;
					Q.push({i, j});
					while(!Q.empty()){
						auto cur = Q.front(); Q.pop();
						for(int dir = 0;dir < 4;dir++){
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
							if(vis[nx][ny]) continue;
							if(!box[nx][ny]){
								if(box[cur.X][cur.Y])
									box[cur.X][cur.Y]--;
								continue;
							}
							Q.push({nx, ny});
							vis[nx][ny] = 1;
						}
					}
				}
			}
		}
		
		for(int i = 0;i < n;i++)
			fill(vis[i], vis[i] + m, 0);
		int cnt = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(box[i][j] && !vis[i][j]){
					cnt++;
					vis[i][j] = 1;
					queue<pair<int, int> > Q;
					Q.push({i, j});
					while(!Q.empty()){
						auto cur = Q.front(); Q.pop();
						for(int dir = 0;dir < 4;dir++){
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
							if(vis[nx][ny] || !box[nx][ny]) continue;
							Q.push({nx, ny});
							vis[nx][ny] = 1;
						}
					}
				}
			}
		}
		for(int i = 0;i < n;i++)
			fill(vis[i], vis[i] + m, 0);
		if(cnt >= 2){
			cout << v << '\n';
			return 0;
		}
		if(!cnt){
			cout << 0 << '\n';
			return 0;
		}
	}
}
