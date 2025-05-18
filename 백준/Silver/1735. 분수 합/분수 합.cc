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

	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);

        int a, b, c, d;
        int n, m, x, y, r;

        cin >> a >> b >> c >> d;

        n = x = a * d + b * c; //자
        m = y = b * d; //모

        //n, m의 최대공약수 구하기
        while (y != 0) 
        {
            r = x % y;
            x = y;
            y = r;
        }

        cout << n / x << ' ' << m / x << '\n';

        return 0;
    }

 