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
#include <regex>

using namespace std;
#define MAXX 2147483647


char c1[10001], c2[10001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
	int n1, n2, idx = 0, p = 0, s1, s2, ans[10001];

	cin >> c1 >> c2;
	s1 = strlen(c1); s2 = strlen(c2);
	while (s1 || s2 || p) 
	{
		if (s1)	
			n1 = c1[(s1--) - 1] - '0';
		if (s2)	
			n2 = c2[(s2--) - 1] - '0';

		ans[idx++] = (n1 + n2 + p) % 10;
		p = n1 + n2 + p > 9 ? 1 : 0;
		n1 = n2 = 0;
	}
	for (int a = idx - 1; a >= 0; a--)
		cout << ans[a];
    return 0;
}