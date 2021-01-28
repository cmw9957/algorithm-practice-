#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int box[305][305];
bool vis[305][305];

int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int l;
		cin >> l;
		int x, y, ax, ay;
		cin >> x >> y;
		cin >> ax >> ay;
		queue<pair<int , int> > Q;
		Q.push({x, y});
		vis[x][y] = 1;
		bool findVal = false;
		while(!Q.empty()){
			auto cur = Q.front(); Q.pop();
			for(int dir = 0; dir < 8;dir++){
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
				if(vis[nx][ny]) continue;
				box[nx][ny] = box[cur.X][cur.Y] + 1;
				if(box[ax][ay]){
					findVal = true;
					break;
				}
				vis[nx][ny] = 1;
				Q.push({nx, ny});
			}
			if(findVal) break;
		}
		cout << box[ax][ay] << '\n';
		for(int i = 0;i < l;i++)
			fill(box[i], box[i] + l, 0);
		for(int i = 0;i < l;i++)
			fill(vis[i], vis[i] + l, 0);
	}
	return 0;
}
