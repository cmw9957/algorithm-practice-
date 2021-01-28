#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int box[102][102];
bool vis[102][102];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n, k;
	cin >> m >> n >> k;
	while(k--){							//이 부분에서 실수했다. 변수 k를 사용하고 있었는데 왜그랬지 
		int x1, x2, y1, y2;				//엄청난 삽질 이였다. 
		cin >> x1 >> y1 >> x2 >> y2;
		for(int i = x1;i < x2;i++){
			for(int j = y1;j < y2;j++)
				box[j][i] = 1;
		}
	}
//	for(int i = 0;i < m;i++){
//		for(int j = 0;j < n;j++)
//			cout << box[i][j] << ' ';
//		cout << '\n';
//	}
	vector<int> V;
	queue<pair<int, int> > Q;
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			if(!box[i][j] && !vis[i][j]){
				Q.push({i, j});
				vis[i][j] = 1;
				int cnt = 1;					//check
				while(!Q.empty()){
					auto cur = Q.front(); Q.pop();
					for(int dir = 0;dir < 4;dir++){
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
						if(box[nx][ny] || vis[nx][ny]) continue;
						Q.push({nx, ny});
						vis[nx][ny] = 1;
						cnt++;
					}
				}
				V.push_back(cnt);
			}
		}
	}
	cout << V.size() << '\n';
	sort(V.begin(), V.end());
	for(auto c : V)
		cout << c << ' ';
	return 0;
}
