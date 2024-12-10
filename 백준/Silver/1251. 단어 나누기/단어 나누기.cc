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
#define MAXX 99999999


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	string s;
	cin >> s;

	string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

	for (int a = 0; a < s.length() - 2; a++)
	{
		for (int b = a + 1; b < s.length() - 1; b++) {
			int c = a;
			int d = b;

			string ss = "";
			for (int k = c; k >= 0; k--)
				ss += s[k];
			for (int k = d; k > c; k--)
				ss+= s[k];
			for (int k = s.length() - 1; k > d; k--) 
				ss += s[k];

			if (ans > ss)
				ans = ss;
		}
	}
	cout << ans;
}
