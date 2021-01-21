#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	list<int> l;
	int n, k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		l.push_back(i);
	list<int>::iterator t = l.begin();
	k--;
	cout << "<";
	while(n--){
		for(int i = 0;i < k;i++){
			t++;
			if(t == l.end()) t = l.begin();
		}
		cout << *t;
		
		if(n)
			cout << ", ";
		
		l.erase(t++);
		if(t == l.end()) t = l.begin();
	}
	cout << ">";
	return 0;
}
