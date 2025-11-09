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
    cin.tie(0);
    cout.tie(0);
    
	int N;
	int ct = 0;

	cin >> N;

	if (N < 10) 
	{
		cout << N;
		return 0;
	}

	for (int a = 1; a <= N; a *= 10) 
		ct += N - a + 1;
	

	cout << ct;


    return 0;
}