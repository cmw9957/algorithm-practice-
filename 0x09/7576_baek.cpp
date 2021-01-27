#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int box[1005][1005];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1}; 

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n;
	cin >> m >> n;
	queue<pair<int, int> > Q;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			cin >> box[i][j];
			if(box[i][j] == 1)
				Q.push({i, j});
		}
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for(int dir = 0;dir < 4;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(box[nx][ny] != 0) continue;
			box[nx][ny] = box[cur.X][cur.Y] + 1;
			Q.push({nx, ny});
		}
	}
	int day = 0;
	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			day = max(day, box[i][j]);
			if(box[i][j] == 0){
				cout << -1 << '\n';
				return 0;
			}
		}
	}
		
	
	cout << day - 1 << '\n';
	return 0;
}
