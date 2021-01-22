#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<pair<int, int> > S;
	int n;
	cin >> n;
	int height;
	
	for(int i = 1;i <= n;i++){
		cin >> height;
		
		while(!S.empty()){
			if(height < S.top().second){
				cout << S.top().first << ' ';
				S.push(make_pair(i, height));
				break;
			}
			S.pop();
		}
		
		if(S.empty())
			cout << "0" << ' ';
			
		
		S.push(make_pair(i, height));
	}
	
	return 0;
}
