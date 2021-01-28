#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string s[30];
char box[30][30];
bool vis[30][30];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> s[i];
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			box[i][j] = s[i][j];
		}
	}
//	for(int i = 0;i < n;i++){
//		for(int j = 0;j < n;j++){
//			cout << box[i][j] << ' ';
//		}
//		cout << '\n'
//	}
	queue<pair<int, int> > Q;
	vector<int> V;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(box[i][j] == '1' && !vis[i][j]){
				vis[i][j] = 1;
				Q.push({i, j});
				int size = 1;
				while(!Q.empty()){
					auto cur = Q.front(); Q.pop();
					for(int dir = 0;dir < 4;dir++){
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if(box[nx][ny] == '0' || vis[nx][ny]) continue;
						vis[nx][ny] = 1;
						Q.push({nx, ny});
						size++;
					}
				}
				V.push_back(size);
			}
		}
	}
	sort(V.begin(), V.end());
	cout << V.size() << '\n';
	for(auto c : V)
		cout << c << '\n';
	return 0;
}
