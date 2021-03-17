#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, m;
int lx, ly;
bool connect;
string box[1505];
bool vis[1505][1505][2];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<int, int> > ice;
queue<pair<int, int> > bird;
queue<pair<int ,int> > next_ice;
queue<pair<int, int> > next_bird;

void find_bird(){
	while(!next_bird.empty()){
		auto cur = next_bird.front(); next_bird.pop();
		for(int dir = 0;dir < 4;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if(vis[nx][ny][1]) continue;
			if(box[nx][ny] == 'X'){
				vis[nx][ny][1] = true;
				bird.push({nx, ny});
				continue;
			}
			if(box[nx][ny] == 'L'){
				connect = true;
				return ;
			}
			vis[nx][ny][1] = true;
			next_bird.push({nx, ny});
		}
	}
	swap(bird, next_bird);
}

void melting_ice(){
	while(!next_ice.empty()){
		auto cur = next_ice.front(); next_ice.pop();
		box[cur.X][cur.Y] = '.';
		for(int dir = 0;dir < 4;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if(box[nx][ny] != 'X' || vis[nx][ny][0]) continue;
			vis[nx][ny][0] = true;
			ice.push({nx, ny});
		}
	}
	swap(ice, next_ice);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 0;i < n;i++)
		cin >> box[i];
	bool fd = false;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(box[i][j] == 'L'){
				lx = i;
				ly = j;
				fd = true;
				break;
			}
		}
		if(fd) break;
	}
	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(box[i][j] != 'X' && !vis[i][j][0]){
				vis[i][j][0] = true;
				ice.push({i, j});
				while(!ice.empty()){
					auto cur = ice.front(); ice.pop();
					for(int dir = 0;dir < 4;dir++){
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if(vis[nx][ny][0]) continue;
						if(box[nx][ny] == 'X'){
							next_ice.push({nx, ny});
							vis[nx][ny][0] = true;
							continue;
						}
						vis[nx][ny][0] = true;
						ice.push({nx, ny});
					}
				}
			}
		}
	}
	
	bird.push({lx, ly});
	vis[lx][ly][1] = true;
	while(!bird.empty()){
		auto cur = bird.front(); bird.pop();
		for(int dir = 0;dir < 4;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if(vis[nx][ny][1]) continue;
			if(box[nx][ny] == 'X'){
				next_bird.push({nx, ny});
				vis[nx][ny][1] = true;
				continue;
			}
			if(box[nx][ny] == 'L'){
				cout << 0;
				return 0;
			}
			vis[nx][ny][1] = true;
			bird.push({nx, ny});
		}
	}
	for(int c = 1;;c++){
		melting_ice();
		find_bird();
//		cout << '\n';
//		for(int i = 0;i < n;i++){
//			cout << box[i] << '\n';
//		}
//		cout << '\n';
		if(connect){
			cout << c;
			return 0;
		}
	}
	return 0;
}
