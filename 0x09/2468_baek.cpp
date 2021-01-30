#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int box[105][105];
bool vis[105][105];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			cin >> box[i][j];
	int max_safe_area = 0;
	for(int i = 0;;i++){
		
		for(int j = 0;j < n;j++){
			for(int k = 0;k < n;k++){
				if(box[j][k] <= i && !vis[j][k]){
					queue<pair<int, int> > Q;
					Q.push({j, k});
					vis[j][k] = 1;
					while(!Q.empty()){
						auto cur = Q.front(); Q.pop();
						for(int dir = 0;dir < 4;dir++){
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if(box[nx][ny] > i || vis[nx][ny]) continue;
							Q.push({nx, ny});
							vis[nx][ny] = 1;
						}
					}
				}
			}
		}
		
		int cnt = 0;
		for(int j = 0;j < n;j++){
			for(int k = 0;k < n;k++){
				if(vis[j][k] == 0){
					cnt++;
					queue<pair<int, int> > Q;
					Q.push({j, k});
					vis[j][k] = 1;
					while(!Q.empty()){
						auto cur = Q.front(); Q.pop();
						for(int dir = 0;dir < 4;dir++){
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if(vis[nx][ny]) continue;
							Q.push({nx, ny});
							vis[nx][ny] = 1;
						}
					}
				}
			}
		}
		if(!cnt) break;		//다음 안전 영역이 적다고해서 무조건 지금 안전영역이 제일 많다고 확신할 수 없다. 다 침수 될 때 까지 비교한다. 
		max_safe_area = max(max_safe_area, cnt);
		for(int j = 0;j < n;j++)
			fill(vis[j], vis[j] + n, 0);
	}
	cout << max_safe_area << '\n';
	return 0;
}
