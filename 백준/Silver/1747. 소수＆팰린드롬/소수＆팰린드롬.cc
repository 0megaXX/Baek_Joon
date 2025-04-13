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



bool PN[1003002];



bool isSame(int N) {
	string s = to_string(N);
	int size = s.size();
	for (int i = 0, j = size - 1; i < size, j >= 0; i++, j--) {
		if (s[i] != s[j]) return false;
	}
	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	for (int a = 2; a <= 1003002; a++) 
		PN[a] = true;
	
	PN[0] = false;
	PN[1] = false;
	for (int a = 2; a <= 1003002; a++) 
	{
		for (int b = 2; b * b <= a; b++) 
		{
			if (a % b == 0)
			{
				PN[a] = false;
				break;
			}
		}
	}

	for (int a = n; a <= 1003002; a++)
	{
		if (PN[a] && isSame(a))
		{
			cout << a << "\n";
			break;
		}
	}
	return 0;
}

