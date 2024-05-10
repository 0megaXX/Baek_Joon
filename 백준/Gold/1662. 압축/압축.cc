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
	#include <unordered_map>

	using namespace std;

	string S;
	int len[51], K[51];

	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
	
		cin >> S;
		int i, cur = 0, num = 0;
		for (i = 0; i < S.length(); i++) {
			if (S[i] == '(') 
			{
				len[cur]--;	// 괄호 앞의 K는 길이에 포함시키지 않으므로
				cur++;
				K[cur] = num;	// 아래 else 문에서 저장한 숫자를 괄호 앞 숫자로 확정
			}
			else if (S[i] == ')') 
			{
				int temp = len[cur] * K[cur];
				len[cur] = 0;	// 해당 괄호는 끝났으므로 0으로 초기화
				cur--;
				len[cur] += temp;
			}
			else 
			{
				len[cur]++;
				num = S[i] - '0';	// 괄호 앞 숫자일 수 있으므로 일단 저장
			}
		}
		cout << len[0];
	}