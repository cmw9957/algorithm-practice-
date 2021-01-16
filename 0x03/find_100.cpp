//주어진 길이 N의 int 배열 arr에서 합이 100인 서로 다른 위치의 두 원소가 존재하면 1을 존재하지 않으면 0을 반환하는 함수
//func2(int arr[], int N)을 작성하라. ar의 각 수는 0 이상 100 이하이고 N은 1000이하이다.
#include<bits/stdc++.h>
using namespace std;

int func(int arr[], int N){
	int num_cnt[101] = {0};
	for(int i = 0;i < N;i++){
		if(num_cnt[100 - arr[i]]) return 1;
		num_cnt[arr[i]]++;
	}
	
	return 0;
} 

int main(void){
	int arr[5] = {1, 23, 53, 77, 60};
	int N = 5;
	printf("%d", func(arr, N));
	return 0;
}
