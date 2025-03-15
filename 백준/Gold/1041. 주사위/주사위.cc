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
#include <tuple>

using namespace std;
#define MAXX 2147483647


vector<int> v(6); 
int one = 5000, two = 5000, three = 5000; //1면,2면,3면 최소조합
int largest, summ; //가장 큰눈 , 눈의합


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long N, rs;

	cin >> N;

	for (int a = 0; a < 6; a++) {
		cin >> v[a];
		summ += v[a];
		largest = max(largest, v[a]);
	}

	//마주보는 조합만 피하기 (0,5) , (1,4) , (2,3) -> 인덱스 합 : 5
	for (int a = 0; a < 6; a++) {
		one = min(one, v[a]);
		for (int b = a + 1; b < 6; b++) 
		{
			if (a + b == 5) continue;
			two = min(v[a] + v[b], two);
			for (int c = b + 1; c < 6; c++)
			{
				if (a + c == 5 || b + c == 5) 
					continue;
				three = min(three, v[a] + v[b] + v[c]);
			}
		}
	}

	if (N == 1)
		rs = summ - largest;
	else 
		rs = (4 * three) + ((8 * N - 12) * two) + (5 * N - 6) * (N - 2) * one;
	cout << rs;
    return 0;
}

