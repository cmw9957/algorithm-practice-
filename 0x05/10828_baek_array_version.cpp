#include<bits/stdc++.h>
using namespace std;

const int MX = 10005;
int dat[MX];
int pos = 0;

void push(int x){
	dat[pos++] = x;
}

int pop(){
	if(!pos) return -1;
	pos--;
	return dat[pos];
}

int top(){
	if(!pos) return -1;
	return dat[pos - 1];
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	while(n--){
		string str;
		cin >> str;
		
		if(str == "push"){
			int num;
			cin >> num;
			push(num);
		}
		else if(str == "pop"){
			cout << pop() << '\n';
		}
		else if(str == "size"){
			cout << pos << '\n';
		}
		else if(str == "empty"){
			cout << (int)(pos == 0) << '\n';
		}
		else if(str == "top"){
			cout << top() << '\n';
		}
	}
	
	return 0;
}
