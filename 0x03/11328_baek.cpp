#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	string str1, str2;
	cin >> N;
	
	for(int i = 0;i < N;i++){
		int cnt[26] = {0};
		bool a = true;
		cin >> str1 >> str2;
		
		if(str1.length() != str2.length()){
			cout << "Impossible" << '\n';
			continue;
		}
		
		for(int i = 0;i < str1.length();i++){
			cnt[str1[i] - 'a']++;
			cnt[str2[i] - 'a']--;
		}
		for(int i = 0;i < 26;i++){
			if(cnt[i] != 0){
				cout << "Impossible" << '\n';
				a = false;
				break;
			}
		}
		if(a) cout << "Possible" << '\n';
	}
	
	return 0;
}
