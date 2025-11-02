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

string s;

bool fn(int l, int r)
{
	while (l < r)
    {
		if (s[l] != s[r])
            return 0;
		l++;
        r--;
	}
   
	return 1;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    cin >> s;
	int len = s.length();
	for (int a = 0; a < len; a++)
		if (fn(a, len - 1)) // 앞에 a만큼 넣기로 이미 정함
        {
			cout << len + a;
			return 0;
		}
	

    return 0;
}