#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <stddef.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <sstream>
#include <cmath>
#include<map>
#include <queue>
#include <stack>
#include <cstring>
#include <deque>
#include <set>
#include <unordered_set>
#include <chrono>

using namespace std;
#define MAXX 2147483647


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int N, K = 0; //N,K는 자연수
	cin >> N >> K;
	//0 < N <= 10000, 0 < K <=N 

	int divisor[10000] = { 0, }; //약수를 저장하는 배열 0으로 초기화

	int num = 0; //약수의 개수
	for (int a= 1; a <= N; a++) {
		if (N % a == 0) {
			divisor[num] = a; //약수 저장
			num++;
		}
	}

	if (num < K) { //K번째 약수가 존재하지 않을 경우
		cout << "0" << endl;
	}
	else
		cout << divisor[K - 1] << endl;

	return 0;


}