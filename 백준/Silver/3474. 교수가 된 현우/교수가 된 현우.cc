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


set<string> Set;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int T, N;
    cin >> T;

	for (int a = 0; a < T; a++) 
	{

		cin >> N;
		int rs = 0, num = 5;

		while (num <= N) 
		{
			rs = rs + (N / num);
			num *= 5;
		}
		cout << rs << "\n";
	}

    return 0;
}