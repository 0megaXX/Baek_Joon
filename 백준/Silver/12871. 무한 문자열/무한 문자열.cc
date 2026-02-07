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


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	string s1, s2, tmp_s1, tmp_s2;

	int s1_len, s2_len;

	cin >> s1 >> s2;
	s1_len = s1.length(), s2_len = s2.length();

	for (int a = 0; a < s2_len; a++) 
		tmp_s1 += s1;
	for (int a = 0; a < s1_len; a++)
		tmp_s2 += s2;

	if (tmp_s1 == tmp_s2) 
		cout << 1;

	else cout << 0;

    return 0;
}