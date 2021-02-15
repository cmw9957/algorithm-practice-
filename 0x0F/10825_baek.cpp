#include<bits/stdc++.h>
using namespace std;
#define N get<0>
#define K get<1>
#define E get<2>
#define M get<3>

bool cmp(tuple<string, int, int, int> a, tuple<string, int, int, int> b){
	if(K(a) == K(b)){
		if(E(a) == E(b)){
			if(M(a) == M(b))
				return N(a) < N(b);
			
			return M(a) > M(b);
		}
		return E(a) < E(b);
	}
	return K(a) > K(b);
}

vector<tuple<string, int, int, int> > v;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		string name;
		int k_score, e_score, m_score;
		cin >> name >> k_score >> e_score >> m_score;
		v.push_back(make_tuple(name, k_score, e_score, m_score));
	}
	sort(v.begin(), v.end(), cmp);
	for(auto c : v) cout << N(c) << '\n';
	return 0;
}
