#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<int> s;
	vector<char> a;
	int arr[100001];
	int n;
	cin >> n;
	for(int i = 0; i < n;i++)
		cin >> arr[i];
	
	int index = 0;
	for(int i = 1;i <= n;i++){
		s.push(i);
		a.push_back('+');
		
		while(!s.empty() && arr[index] == s.top()){
			s.pop();
			a.push_back('-');
			index++;
		}
	}
	
	if(!s.empty()) cout << "NO" << '\n';
	else{
		for(auto c : a) cout << c << '\n';
	}
	
	return 0;
}
