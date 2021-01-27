#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
string board[1002];
int dp[1002][1002];
int df[1002][1002];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r, c;
	cin >> r >> c;
	for(int i = 0;i < r;i++){
		fill(df[i], df[i] + c, -1);
		fill(dp[i], dp[i] + c, -1);
	}
	for(int i = 0;i < r;i++)
		cin >> board[i];
	queue<pair<int, int> > QP;
	queue<pair<int, int> > QF;
	for(int i = 0;i < r;i++){
		for(int j = 0;j < c;j++){
			if(board[i][j] == 'J'){
				dp[i][j] = 1;
				QP.push({i, j});
			}
			else if(board[i][j] == 'F'){
				df[i][j] = 1;
				QF.push({i, j});
			}
		}
	}
	
	while(!QF.empty()){
		auto cur = QF.front(); QF.pop();
		for(int dir = 0;dir < 4;dir++){
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if(board[nx][ny] == '#' || df[nx][ny] != -1) continue;
			df[nx][ny] = df[cur.x][cur.y] + 1;
			QF.push({nx, ny});
		}
	}
	
	while(!QP.empty()){
		auto cur = QP.front(); QP.pop();
		for(int dir = 0;dir < 4;dir++){
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if(nx < 0 || nx >= r || ny < 0 || ny >= c){
				cout << dp[cur.x][cur.y] << '\n';
				return 0;
			}
			if(board[nx][ny] == '#' || dp[nx][ny] >= 0) continue;
			if(df[nx][ny] != -1 && df[nx][ny] <= dp[cur.x][cur.y] + 1) continue;
			dp[nx][ny] = dp[cur.x][cur.y] + 1;
			QP.push({nx, ny});
		}
	}
	cout << "IMPOSSIBLE" << '\n';
	return 0;
}
