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


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        vector<int> a, b, c;
        int n;
        cin >> n;
        a.resize(n);
        for (auto& u : a) cin >> u;
        cin >> n;
        b.resize(n);
        for (auto& u : b) cin >> u;
        cin >> n;
        c.resize(n);
        for (auto& u : c) cin >> u;

        set<int> _s;
        for (auto u : a) {
            for (auto v : b) {
                for (auto w : c) {
                    int sum = u + v + w;
                    string s = to_string(sum);
                    bool check = true;
                    for (auto _c : s) {
                        if (!(_c == '5' || _c == '8')) {
                            check = false;
                            break;
                        }
                    }
                    if (check) _s.insert(sum);
                }
            }
        }
        cout << _s.size() << "\n";
    }
    return 0;
}

