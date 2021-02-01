#include<bits/stdc++.h>
using namespace std;
int box[35][35][35];
string s[35][35]; 
int du[] = {1, -1, 0, 0, 0, 0};
int dx[] = {0, 0, -1, 0, 1, 0};
int dy[] = {0, 0, 0, 1, 0, -1};
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1){
		int l, r, c;
		cin >> l >> r >> c;
		if(!l && !r && !c) return 0;
		for(int i = 0; i < l;i++){
			for(int j = 0;j < r;j++){
				cin >> s[i][j];
			}
		}
		queue<tuple<int, int, int> > Q;
		bool out = false;
		for(int i = 0;i < l;i++){
			for(int j = 0;j < r;j++){
				for(int k = 0;k < c;k++){
					if(s[i][j][k] == 'S'){
						box[i][j][k] = 1;
						Q.push(make_tuple(i, j, k));
						out = true;
						break;
					}
				}
				if(out) break;
			}
			if(out) break;
		}
		bool find_ans = false;
		while(!Q.empty()){
			auto cur = Q.front(); Q.pop();
			int u, x, y;
			tie(u, x, y) = cur;
			for(int dir = 0;dir < 6;dir++){
				int nu = u + du[dir];
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if(s[u][x][y] == 'E'){
					cout << "Escaped in " << box[u][x][y] - 1 << " minute(s)." << '\n';
					find_ans = true;
					break;
				}
				if(nu < 0 || nu >= l || nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if(s[nu][nx][ny] == '#' || box[nu][nx][ny] != 0) continue;
				Q.push(make_tuple(nu, nx, ny));
				box[nu][nx][ny] = box[u][x][y] + 1;
			}
			if(find_ans) break;
		}
		if(!find_ans)
			cout << "Trapped!" << '\n';
		for(int i = 0;i < l;i++){
			for(int j = 0;j < r;j++)
				fill(box[i][j], box[i][j] + c, 0);
		}
	}
	return 0;
}
