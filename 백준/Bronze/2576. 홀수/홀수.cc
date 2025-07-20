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
       
        int n, min = 100, sum = 0;

        for (int a = 0; a < 7; a++) 
        {
            cin >> n;
            if (n % 2 == 1) 
            {
                sum += n;
                if (n < min) 
                    min = n;
            }
        }
        if (sum == 0)
            cout << -1;
        else cout << sum << '\n' << min;


        return 0;
    }

  