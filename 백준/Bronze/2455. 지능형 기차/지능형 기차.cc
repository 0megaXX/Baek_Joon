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
       
        int num1, num2, total = 0, maxx = 0;

        for (int i = 0; i < 4; i++) {
            cin >> num1 >> num2;
            total += num2 - num1;
            if (total > maxx) 
                maxx = total;
            
        }
        cout << maxx;

        return 0;
    }

  