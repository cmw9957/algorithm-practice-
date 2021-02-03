#include<bits/stdc++.h>
using namespace std;

void func(int a, int b, int n){
	if(n == 1){							//n개의 원판을 세번째 장대로 모두 옮겨야한다. n = 1일때 잘 작동한다. 그러면 된 것이다. 
		cout << a << ' ' << b << '\n';
		return ;
	}
	func(a, 6-a-b, n-1);				//n-1개의 원판을 6-a-b로 모두 옮긴다는 재귀적 사고 
	cout << a << ' ' << b << '\n';		//n번째 가장 큰 원판을 b로 옮긴다는 재귀적 사고 
	func(6-a-b, b, n-1);				//6-a-b에 있던 n-1개의 원판을 b로 옮긴다는 재귀적 사고 
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> k;
	cout << (1<<k) - 1 << '\n';
	func(1, 3, k); 
	return 0;
}
