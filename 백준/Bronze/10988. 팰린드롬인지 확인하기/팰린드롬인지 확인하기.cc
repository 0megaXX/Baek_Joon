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

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    string s;
    cin >> s;

    for (int a = 0; a <= s.length() / 2; a++) {
        if (s[a] != s[s.length() - a - 1]) {
            cout << 0;
            return 0;
        }
    }

    cout << 1;
}