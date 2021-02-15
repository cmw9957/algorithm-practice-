#include<bits/stdc++.h>
using namespace std;
int n, c;
map<int, int> cnt;
map<int, int> chk;
vector<pair<int, int> > v;

bool cmp(pair <int, int> a, pair<int, int> b){
	if(a.second == b.second) return chk[a.first] < chk[b.first];
	return a.second > b.second;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	for(int i = 0;i < n;i++){
		int num;
		cin >> num;
		cnt[num]++;
		if(!chk[num]) chk[num] = i+1;	//ÀûÈù ¼ø¼­ 
	}
	for(auto c : cnt)
		v.push_back({c.first, c.second});
	sort(v.begin(), v.end(), cmp);
	for(auto c : v){
		for(int i = 0;i < c.second;i++)
			cout << c.first << ' ';
	}
	return 0;
}
