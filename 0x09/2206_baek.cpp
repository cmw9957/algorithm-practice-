#include<bits/stdc++.h>
using namespace std;
string box[1005];
int vis[1005][1005][2];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	if(n == 1 && m == 1){
		cout << 1;
		return 0;
	}
	
	for(int i = 0;i < n;i++)
		cin >> box[i];
	
	queue<tuple<int, int, int> > Q;
	Q.push(make_tuple(0, 0, 1));
	vis[0][0][1] = 1;
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		int x, y, a;
		tie(x, y, a) = cur;
		for(int dir = 0;dir < 4;dir++){
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int at = a;
			if(nx == n-1 && ny == m-1){
				cout << vis[x][y][at]+1;
				return 0;
			}
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(!at && box[nx][ny] == '1') continue;
			if(!at && vis[nx][ny][1] || vis[nx][ny][at]) continue;
			if(at && box[nx][ny] == '1'){
				vis[nx][ny][0] = vis[x][y][at] + 1;
				Q.push(make_tuple(nx, ny, 0));
				continue;
			}
			vis[nx][ny][at] = vis[x][y][at] + 1;
			Q.push(make_tuple(nx, ny, at));
		}
	}
	cout << -1;
	return 0;
}
