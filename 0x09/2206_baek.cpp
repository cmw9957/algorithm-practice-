#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string s[1002];
int box[1002][1002];
bool vis[1002][1002][2];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0;i < n;i++)
		cin >> s[i];
	for(int i =0;i < n;i++)
		for(int j = 0;j < m;j++){
			box[i][j] = s[i][j] - '0';
		}
	if(n == 1 && m == 1){
		cout << 1 << '\n';
		return 0;
	}
	
	queue<tuple<int, int, int, int> > Q;
	Q.push(make_tuple(0, 0, 1, 1));
	vis[0][0][0] = 1;
	vis[0][0][1] = 1;
	
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for(int dir = 0;dir < 4;dir++){
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			if(get<0>(cur) == n - 1 && get<1>(cur) == m - 1){
				cout << get<3>(cur) << '\n';
				return 0;
			}
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(box[nx][ny] == 1 && get<2>(cur)){
				vis[nx][ny][get<2>(cur)] = 1;
				Q.push(make_tuple(nx, ny, get<2>(cur) = false, get<3>(cur) + 1));
			}
			if(box[nx][ny] == 0 && !vis[nx][ny][get<2>(cur)]){
				vis[nx][ny][get<2>(cur)] = 1;
				Q.push(make_tuple(nx, ny, get<2>(cur), get<3>(cur) + 1));
			}
			cout << "===>" << nx << ' ' << ny << ' ' << get<2>(cur) << ' ' << get<3>(cur) << '\n' << '\n';
		}
	}
	cout << -1 << '\n';
	return 0;
}


