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


bool fail[1000];

void check(string str, int st, int ba) {
    int a, b;
    for (int i = 123; i < 988; i++) {
        if (fail[i]) continue;
        a = 0, b = 0;
        string tmp = to_string(i);
        for (int k = 0; k < 3; k++) {
            for (int s = 0; s < 3; s++) {
                if (str[s] == tmp[k]) {
                    if (s == k) a++;
                    else b++;
                }
            }
        }
        if (a != st || b != ba) {
            fail[i] = true;
        }
    }
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, z, x;
    string tmp;
    cin >> n;
    for (int a = 0; a < n; a++) {
        cin >> tmp >> z >> x;
        check(tmp, z, x);
    }
    int ans = 0;
    int num;
    for (int a = 1; a < 10; a++) {
        for (int b = 1; b < 10; b++) {
            if (a == b)
                continue;
            for (int c = 1; c < 10; c++)
            {
                if (c == a || c == b)
                    continue;
                num = a * 100 + b * 10 + c;
                if (!fail[num])
                    ans++;
            }
        }
    }
    cout << ans;
    return 0;
}

