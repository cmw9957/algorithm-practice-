//시간복잡도는 b가 절반씩 깎이기 때문에 O(log b)이다. 

#include<iostream>
using namespace std;

using ll = long long;

ll pow(ll a, ll b, ll c){
	if(b == 1) return a % c;
	ll val = pow(a, b/2, c);
	val = val * val % c;
	if(b % 2 == 0) return val;
	return val * a % c;
}

int main(){
	ll a, b, c;
	cin >> a >> b >> c;
	cout << pow(a, b, c);
}
