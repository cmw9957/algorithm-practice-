#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
int t;
pair<int, char> box[5][5];
pair<int, char> temp[5][5];
pair<int, char> mat[10][4][4];

void get_mat(int cur){
	for(int i = 0;i < 4;i++)
		for(int j = 0;j < 4;j++)
			cin >> mat[cur][i][j].F;
		
	for(int i = 0;i < 4;i++)
		for(int j = 0;j < 4;j++)
			cin >> mat[cur][i][j].S;
}

void func(int cur){
	
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for(int i = 0;i < t;i++) get_mat(i);
	
	return 0;
}
