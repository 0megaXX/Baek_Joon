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
       
        int n, q;
        cin >> n >> q;
        vector<int> v(n);
        vector<int> summ(n + 1);
        for (int a = 0; a < n; a++) 
            cin >> v[a];
        sort(v.begin(), v.end());

        summ[1] = v[0];
        for (int a = 2; a <= n; a++) 
            summ[a] = summ[a - 1] + v[a - 1];

        while (q--)
        {
            int c, d;
            cin >> c >> d;
            cout << summ[d] - summ[c - 1] << "\n";
        }

        return 0;
    }

  