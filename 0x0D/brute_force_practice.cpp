#include<bits/stdc++.h>
using namespace std;
#define R 12
#define C 6
#define X first
#define Y second
int explo[R][C];
string box[R];
bool vis[R][C];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void fall(){
	for(int i = 0;i < C;i++){
		char temp[R] = {};
		int idx = 0;
		fill(temp, temp + R, '.');
		for(int j = R-1;j >= 0;j--)
			if(box[j][i] != '.') 
				temp[idx++] = box[j][i];
		
		idx = 0;
		for(int j = R-1;j >= 0;j--) 
			box[j][i] = temp[idx++];
	}
}

void func(int num){
	for(int i = 0;i < R;i++){
		for(int j = 0;j < C;j++){
			if(explo[i][j] == num) box[i][j] = '.';
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i = 0;i < R;i++)
		cin >> box[i];
	int ans_cnt = 0;
	bool boom = false;
	do{
		int num = 0;
		boom = false;
		for(int i = 0;i < R;i++){
			for(int j = 0;j < C;j++){
				
				if(box[i][j] != '.' && !vis[i][j]){
					num++;
					explo[i][j] = num;
					int boom_cnt = 0;
					boom_cnt++;
					vis[i][j] = 1;
					queue<pair<int, int> > Q;
					Q.push({i, j});
					while(!Q.empty()){
						auto cur = Q.front(); Q.pop();
						for(int dir = 0;dir < 4;dir++){
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
							if(vis[nx][ny] || box[nx][ny] != box[cur.X][cur.Y]) continue;
							explo[nx][ny] = num;
							boom_cnt++;
							vis[nx][ny] = 1;
							Q.push({nx, ny});
						}
					}
					if(boom_cnt >= 4){
						boom = 1;
						func(num);
					}
				}
				
			}
		}
		if(boom) ans_cnt++;
		for(int i = 0;i < R;i++){
			fill(vis[i], vis[i] + C, 0);
			fill(explo[i], explo[i] + C, 0);
		}
		fall();
	}while(boom);
	cout << ans_cnt;
	return 0;
}
