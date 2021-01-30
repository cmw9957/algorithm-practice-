#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char box[1002][1002];
int vis[1002][1002];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1}; 
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int is_right = false;
		int h, w;
		cin >> h >> w;
		for(int i = 0;i < w;i++){
			for(int j = 0;j < h;j++)
				cin >> box[i][j];
		}
		queue<tuple<int, int, int, int> > Q;
		for(int i = 0;i < w;i++){
			for(int j = 0;j < h;j++){
				if((box[i][j] == '@' || box[i][j] == '*') && !vis[i][j]){
					if(box[i][j] == '@')
						Q.push(make_tuple(i, j, 1, 1));
					else
						Q.push(make_tuple(i, j, 1, 0));
					vis[i][j] = 1;
				}
			}
		}
		while(!Q.empty()){
			auto cur = Q.front(); Q.pop();
			for(int dir = 0;dir < 4;dir++){
				int nx = get<0>(cur) + dx[dir];
				int ny = get<1>(cur) + dy[dir];
				int walk = get<2>(cur);
				int type = get<3>(cur);
				if(nx < 0 || nx >= w || ny < 0 || ny >= h){
					if(type){
//						cout << "=========================" << '\n';
//						for(int i = 0;i < w;i++){
//							for(int j = 0;j < h;j++){
//								cout << vis[i][j] << ' ';
//							}
//							cout << '\n';
//						}
//						cout << "=========================" << '\n';
						cout << walk << '\n';
						is_right = true;
						break;
					}
					continue;
				}
				if(type && vis[nx][ny]) continue;
				if(box[nx][ny] == '#' || box[nx][ny] == '*' || vis[nx][ny] == -1) continue; 
				Q.push(make_tuple(nx, ny, walk + 1, type));
				
				if(!type)
					vis[nx][ny] = -1;
				else
					vis[nx][ny] = 1;
			}
			if(is_right) break;
		}
		if(!is_right)
			cout << "IMPOSSIBLE" << '\n';
		for(int i = 0;i < h;i++){
			fill(vis[i], vis[i] + w, 0);
			fill(box[i], box[i] + w, '.');
		}
			
	}
	return 0;
}
