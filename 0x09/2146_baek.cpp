//모든 섬에 대해서 생각해보지 않고 안일하게 처음 한개의 섬을 가지고만 계산하려고했다. 

#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int box[105][105];
int road[105][105];
bool vis[105][105];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> ans;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin >> box[i][j];
		}
	}
	int cnt = 2;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(box[i][j] == 1){
				vis[i][j] = 1;
				box[i][j] = cnt;
				queue<pair<int, int> > Q;
				queue<pair<int, int> > S;
				Q.push({i, j});
				while(!Q.empty()){
					auto cur = Q.front(); Q.pop();
					for(int dir = 0;dir < 4;dir++){
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if(vis[nx][ny]) continue;
						if(box[nx][ny] == 0){
							if(box[cur.X][cur.Y] < 0) continue;
							
							S.push({cur.X, cur.Y});
							box[cur.X][cur.Y] = -1;
							continue;
						}
						vis[nx][ny] = 1;
						Q.push({nx, ny});
						box[nx][ny] = cnt;
					}
				}
				cnt++;
				
				bool is_right = false;
				while(!S.empty()){
					auto cur = S.front(); S.pop();
					for(int dir = 0;dir < 4;dir++){
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if(vis[nx][ny]) continue;
						if(!vis[nx][ny] && box[nx][ny] != 0){
							ans.push_back(road[cur.X][cur.Y]);
							is_right = true;
							break;
						}
						vis[nx][ny] = 1;
						road[nx][ny] = road[cur.X][cur.Y] + 1;
						S.push({nx, ny});
					}
					if(is_right) break;
				}
				for(int k = 0;k < n;k++){
					fill(vis[k], vis[k] + n, 0);
					fill(road[k], road[k] + n, 0);
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans[0] << '\n';
	return 0;
}
