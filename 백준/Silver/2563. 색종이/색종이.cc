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


int arr[100][100];
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, x, y, cnt = 0;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        for (int a = y; a < y + 10; a++) {
            for (int b = x; b < x + 10; b++) {
                if (!arr[a][b]) {
                    cnt++;
                    arr[a][b] = 1;
                }
            }
        }
    }
    cout << cnt;

}

