#include<bits/stdc++.h>
using namespace std;
int n, m, x, y, k;
int left_right[] = {0, 0};
int box[25][25];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
deque<int> up_down(4, 0);

void func(int dir){
	int pos_x = x + dx[dir-1];
	int pos_y = y + dy[dir-1];
	if(pos_x < 0 || pos_x >= n || pos_y < 0 || pos_y >= m) return ;
	x = pos_x; y = pos_y;
	if(dir == 1){
		deque<int>::iterator it = up_down.begin();
		int temp[2];
		temp[0] = left_right[0];
		temp[1] = left_right[1];
		left_right[0] = *it;
		left_right[1] = *(it+2);
		*it = temp[1];
		*(it+2) = temp[0];
		
		if(box[x][y] != 0){
			*it = box[x][y];
			box[x][y] = 0;
		}
		else 
			box[x][y] = *it;
		cout << *(it+2) << '\n';
	}
	else if(dir == 2){
		deque<int>::iterator it = up_down.begin();
		int temp[2];
		temp[0] = left_right[0];
		temp[1] = left_right[1];
		left_right[1] = *it;
		left_right[0] = *(it+2);
		*it = temp[0];
		*(it+2) = temp[1];
		
		if(box[x][y] != 0){
			*it = box[x][y];
			box[x][y] = 0;
		}
		else 
			box[x][y] = *it;
		cout << *(it+2) << '\n';
	}
	else if(dir == 3){
		int temp = up_down.back();
		up_down.pop_back();
		up_down.push_front(temp);
		deque<int>::iterator it = up_down.begin();
		if(box[x][y] != 0){
			*it = box[x][y];
			box[x][y] = 0;
		}
		else 
			box[x][y] = *it;
		cout << *(it+2) << '\n';
	}
	else if(dir == 4){
		int temp = up_down.front();
		up_down.pop_front();
		up_down.push_back(temp);
		deque<int>::iterator it = up_down.begin();
		if(box[x][y] != 0){
			*it = box[x][y];
			box[x][y] = 0;
		}
		else 
			box[x][y] = *it;
		cout << *(it+2) << '\n';
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> x >> y >> k;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> box[i][j];
	for(int i = 0;i < k;i++){
		int dir;
		cin >> dir;
		func(dir);
	}
	return 0;
}
