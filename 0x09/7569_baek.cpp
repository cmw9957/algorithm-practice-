#include<bits/stdc++.h>											//뒤돌아보면 쉬운 문제 
using namespace std;
int box[102][102][102];
int dh[6] = {0, 0, 0, 0, 1, -1};								//처음에 dh는 3 dx dy의 크기는 4로 해서 각각 크기가 달랐는데 생각해보니 6개로하면 혼동이 없었다. 
int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n, h;
	cin >> m >> n >> h;
	queue<tuple<int, int, int> > Q;								//기존의 bfs와는 달리 인자를 3개를 써야 됬다. 그래서 tuple을 사용 
	bool isRight = false;
	for(int i = 0;i < h;i++){									//맨 처음에 위에 있어야할 상자를 먼저 입력받아서 상자의 순서대로 값을 저장하느라 삽질을 했다. 사실 위아래 순서는 상관 없었다. 
		for(int j = 0;j < n;j++){
			for(int k = 0;k < m;k++){
				cin >> box[i][j][k];
				if(box[i][j][k] == 0) isRight = true;			//다 익지 않았으면 true 
				if(box[i][j][k] == 1)
					Q.push(make_tuple(i, j, k));				//각 상자의 익은 토마토들의 위치 큐에 담는다. 
			}
		}
	}
	if(!isRight){												//처음부터 다 익은 경우로 0을 출력 
		cout << 0 << '\n';
		return 0;
	}
	
	while(!Q.empty()){
		int ch, cx, cy;
		tie(ch, cx, cy) = Q.front(); Q.pop();
		for(int dir = 0;dir < 6;dir++){
				int nh = ch + dh[dir];
				int nx = cx + dx[dir];
				int ny = cy + dy[dir];
				if(nx < 0 || nx >= n || ny < 0 || ny >= m || nh < 0 || nh >= h) continue;
				if(box[nh][nx][ny] != 0) continue;
				box[nh][nx][ny] = box[ch][cx][cy] + 1;			//다른 높이의 토마토들은 무조건 1로 시작되어야한다고 착각해서 삽질을 했다. 
				Q.push(make_tuple(nh, nx, ny));
			}
	}
	int day = 0;
	for(int i = 0;i < h;i++){
		for(int j = 0;j < n;j++){
			for(int k = 0;k < m;k++){
				day = max(day, box[i][j][k]);					//런타임 에러가 자꾸나서 보니 높이에 관해서 예외사항 조건을 처리 안해놔서 그랬던 것이였다. 
				if(!box[i][j][k]){
					cout << -1 << '\n';
					return 0;
				}
			}
		}
	}
	cout << day - 1 << '\n';									//1로 시작했으니 1을 빼줘야한다. 
	return 0;
}
