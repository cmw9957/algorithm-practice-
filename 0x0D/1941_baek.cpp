#include<bits/stdc++.h>
#define MAX 5
#define MAXI 25
#define X first
#define Y second
using namespace std;

string box[MAXI];
bool pos[MAXI];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ans;

bool check_s_cnt(){
	int s_cnt = 0;
	for(int i = 0;i < MAXI;i++){
		if(pos[i]){
			int x = i / 5;
			int y = i % 5;
			if(box[x][y] == 'S') s_cnt++;
		}
	}
	if(s_cnt >= 4) return true;
	else		   return false;
}

bool check_linked(){
	queue<pair<int, int> > Q;
	bool vis[MAX][MAX] = {};
	bool check_box[MAX][MAX] = {};
	
	int temp = 0;
	for(int i = 0;i < MAXI;i++){
		if(pos[i]){
			int x = i / 5;
			int y = i % 5;
			check_box[x][y] = true;
			
			if(!temp){
				Q.push({x, y});
				vis[x][y] = true;
				temp++;
			}
		}
	}
	int cnt = 1;
    while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for(int dir = 0;dir < 4;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			if(!check_box[nx][ny] || vis[nx][ny]) continue;
			vis[nx][ny] = true;
			Q.push({nx, ny});
			cnt++;
		}
	}
	if(cnt == 7) return true;
	else		 return false;
}

void func(int cur, int cnt){
	if(cnt == 7){
		if(check_s_cnt()){
			if(check_linked()) ans++;
		}
		return ;
	}
	
	for(int i = cur;i < 25;i++){
		if(pos[i]) continue;
		pos[i] = true;
		func(i, cnt+1);
		pos[i] = false;
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i = 0;i < MAX;i++)
		cin >> box[i];
	func(0, 0);
	cout << ans;
	return 0;
}
