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





int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int T,X;
    cin >> T;

    while (T--) {
        int Q = 0, D = 0, N = 0, P = 0;
        cin >> X;
        while (X) {
            if (X >= 25) {
                Q++;
                X -= 25;
            }
            else if (X >= 10) {
                D++;
                X -= 10;
            }
            else if (X >= 5) {
                N++;
                X -= 5;
            }
            else {
                P++;
                X -= 1;
            }
        }
        cout << Q << " " << D << " " << N << " " << P << "\n";
    }

}

 