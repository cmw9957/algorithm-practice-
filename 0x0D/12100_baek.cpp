#include<bits/stdc++.h>
using namespace std;
int n;
int box[25][25];
int box2[25][25];

void turn(){
	int temp[25][25];
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			temp[i][j] = box2[i][j];
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			box2[i][j] = temp[n-1-j][i];
}

//숫자 블럭을 이동시키는 함수 
void func(int dir){
	while(dir--) turn();
	for(int i = 0;i < n;i++){
		int idx = 0;
		int temp[25] = {};
		for(int j = 0;j < n;j++){
			if(box2[i][j] == 0) continue;
			if(temp[idx] == 0) temp[idx] = box2[i][j];
			else if(temp[idx] == box2[i][j]) temp[idx++] *= 2;
			else temp[++idx] = box2[i][j];
		}
		for(int j = 0;j < n;j++) box2[i][j] = temp[j];
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int total = 0;
	//원본 입력받기 
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			cin >> box[i][j];
	//최대 5번 이동시켜서 얻을수있는 모든 겨웅의 수는 4^5이다.4(상하좌우 움직이는 겨웅의수) 
	for(int k = 0;k < 1024;k++){
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				box2[i][j] = box[i][j];
		int brute = k;
		//최대 5번 이동하는 경우의 수들 
		for(int i = 0;i < 5;i++){
			//4진법을 이용해 상하좌우 어디로 이동할 것인지 정함
			//4로 나눈 몫은 다음 이동은 어디방향으로 이동할 것인지를 나타냄 
			int dir = brute%4;
			brute/=4;
			func(dir);
		}
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				total = max(total, box2[i][j]);
	}
	cout << total;
	return 0;
}
