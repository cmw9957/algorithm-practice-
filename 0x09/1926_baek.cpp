#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int box[502][502];
int vis[502][502];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1}; 

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> box[i][j];
	int num = 0;
	int wid = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(!box[i][j] || vis[i][j]) continue;
			num++;
			queue<pair<int ,int> > Q;
			Q.push({i, j});
			vis[i][j] = 1;
			int area = 0;
			while(!Q.empty()){
				area++;
				pair<int, int> cur = Q.front();	Q.pop();
				for(int k = 0;k < 4;k++){//주위에 갈수 있는곳 모두 큐에 푸쉬 
					int nx = cur.X + dx[k];
					int ny = cur.Y + dy[k];
					if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if(vis[nx][ny] || !box[nx][ny]) continue;
					vis[nx][ny] = 1;
					Q.push({nx, ny});
				}
			}
			wid = max(wid, area);
		}
	}
	cout << num << '\n' << wid;
	return 0;
}
