#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int cnt[26] = {0}, ans = 0;
	string str1, str2;
	
	cin >> str1 >> str2;
	
	for(int i = 0;i < str1.length();i++)
		cnt[str1[i] - 'a']++;
	
	for(int i = 0;i < str2.length();i++)
		cnt[str2[i] - 'a']--;
	
	for(int i = 0;i < 26;i++)
		ans += abs(cnt[i]);
	
	cout << ans << '\n';
	return 0;
}
