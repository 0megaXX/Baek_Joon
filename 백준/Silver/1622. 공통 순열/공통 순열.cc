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

int cnt1[128], cnt2[128];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
   
	while (getline(cin, s1) && getline(cin, s2))
    {
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));
		for (auto& l : s1)
            cnt1[l]++;
		for (auto& l : s2)
            cnt2[l]++;

		for (char c = 'a'; c <= 'z'; c++)
        {
			int ct = min(cnt1[c], cnt2[c]);
           
			while (ct--)
                cout << c;
		}
		cout << '\n';
	}


    return 0;
}
