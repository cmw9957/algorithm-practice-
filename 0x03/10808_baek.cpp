#include<bits/stdc++.h>
using namespace std;

int word_cnt[30];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	for(auto c : str){
		word_cnt[c - 'a']++;
	}
	for(int i = 0;i < 26;i++)
		cout << word_cnt[i] << ' ';
	return 0;
}
