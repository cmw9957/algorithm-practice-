//이분 탐색을 이용해야 했다. O(logN)

#include<bits/stdc++.h>
using namespace std;

int arr[100001] = {0};

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, x;
	cin >> n;
	
	for(int i = 0;i < n;i++)
		cin >> arr[i];
	
	int ans = 0;
	cin >> x;
	
	sort(arr, arr + n);
	for(int i = 0;i < n;i++){
		
		int low = 0, high = n - 1;
		while(low <= high){
			
			int mid = (high + low) / 2;
			if(arr[mid] == x - arr[i]){
				ans++;
				break;
			}
			else if(arr[mid] < x - arr[i]) low = mid + 1;
			else	high = mid - 1;
		}
	}
	
	cout << ans / 2 << '\n';
	return 0;
}
