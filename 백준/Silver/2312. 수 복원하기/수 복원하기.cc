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

        int tc, N;

        cin >> tc;
        while (tc--)
        {
            cin >> N;
            for (int a = 2, ct;; ++a)
            {
                ct = 0;
                if (N == 1) // N이 1인 경우
                {
                    break;
                }
                while (N % a == 0) // 나머지가 0이면
                {
                    ++ct;
                    N /= a;
                }
                if (ct != 0)
                {
                    cout << a << " " << ct << "\n";
                }
            }
        }
        return 0;
    }

  