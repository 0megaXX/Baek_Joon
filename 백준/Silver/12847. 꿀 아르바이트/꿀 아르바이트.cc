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

     vector<int> v;

    int main() {

	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);
       
        int n, m;
        cin >> n >> m;

   
        long long int summ = 0;
        for (int a = 0; a < n; a++) {
            int num;
            cin >> num;

            v.push_back(num);
            if (a < m) { summ += num; }
        }

        int start = 0;
        int end = m - 1;
        long long  maxx = summ;
        while (1) 
        {
            summ -= v[start];
            start++;
            end++;
            if (end >= n) { break; }
            else {
                summ += v[end];
            }

            if (maxx < summ) { maxx = summ; }
        }
        cout << maxx ;

        return 0;
    }

  