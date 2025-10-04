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

    long long n, rs;
	cin >> n;
	rs = n;

	for (long long a = 2; a * a <= n; a++)
    {
		if (n % a != 0)
            continue;
		rs -= rs / a;
       
		while (n % a == 0)
            n /= a;
	}

	if (n > 1)
        rs -= rs / n;
	cout << rs;
   
    return 0;
}
