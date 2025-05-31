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


 
    vector<int>v(1001);
    int main() {

	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);

     

        int N, K, ct;
        cin >> N >> K;


        int erase = 0;
        for (int a = 2; a <= N; a++)
            for (int b = a; b <= N; b = b + a)
            {

                ct = 0;
                for (int x = 0; v[x] != 0; x++)
                {
                    if (v[x] == b)
                        ct++; 
                }
                if (ct == 0)
                    v[erase++] = b;
            }
        cout << v[K - 1];
        return 0;
    }

 