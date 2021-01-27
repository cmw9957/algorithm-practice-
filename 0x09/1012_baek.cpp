#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int area[52][52] = {0};
		bool vis[52][52] = {0};
		queue<pair<int, int> > Q;
		int m, n, k;
		cin >> m >> n >> k;
		for(int i = 0;i < k;i++){
			int x, y;
			cin >> x >> y;
			area[x][y] = 1;
		}
		int cnt = 0;
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++){
				if(area[i][j] == 1 && !vis[i][j]){
					vis[i][j] = 1;
					Q.push({i, j});
					while(!Q.empty()){
						auto cur = Q.front(); Q.pop();
						for(int i = 0;i < 4;i++){
							int nx = cur.X + dx[i];
							int ny = cur.Y + dy[i];
							if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
							if(!area[nx][ny] || vis[nx][ny]) continue;
							vis[nx][ny] = 1;
							Q.push({nx, ny});
						}
					}
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
