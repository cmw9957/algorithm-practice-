#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<int> S;
	int height;
	int n;
	cin >> n;
	long long cnt = 0;
	while(n--){
		cin >> height;
		
		while(!S.empty()){
			if(S.top() <= height)			//문제를 잘보자 서로다른이라고 높이를 가진다고 생각했기 때문에 틀렸다. 
				S.pop();
			else{
				cnt++;
				S.push(height);
				//앞의 큰 빌딩들의 개수만큼 더하 기 
				if(S.size() > 2)
					cnt += S.size() - 2;
				break;
			}
		}
		
		if(S.empty())
			S.push(height);
	}
	cout << cnt << '\n';
	return 0;
}
