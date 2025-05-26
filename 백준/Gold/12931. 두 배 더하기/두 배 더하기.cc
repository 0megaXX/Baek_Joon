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

 vector<int> b;

int main() {

    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    int n;
	cin >> n;
    
    b.resize(n); // 채울 벡터

	for (int i=0;i<n;i++) 
        cin >> b[i];

	int ct = 0;
	while (true)
    {
		int zero = 0;
		for (int i=0;i<n;i++) 
        {
			if (b[i] % 2) // 나눠지지 않는다면 1로 종료
            {
				 ct++; // 1증가시키는 연산 사용
				 b[i]--;
			}
			if (b[i] != 0)
				zero++;
		}

        
		if (!zero) // 모두 0이라면 종료
			break;

		for (int i=0;i<n;i++) 
			b[i] /= 2;
        ct++; // 전부 절반으로 줄이는 연산 사용
        
	}

	cout << ct;

    return 0;
}