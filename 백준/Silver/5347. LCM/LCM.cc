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


    long long t, a, b;
    long long GCD(long long a, long long b)
    {
        if (a < b) { return GCD(a, b % a); }
        if (b == 0) { return a; }
        return GCD(b, a % b);
    }
    int main() {

	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);

        cin >> t;
        while (t--)
        {
            cin >> a >> b;
            cout << (a / GCD(a, b)) * (b / GCD(a, b)) * GCD(a, b) << '\n';
        }
        return 0;
    }

  