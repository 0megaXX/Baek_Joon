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

    long arr[100000];
    long psum[100000];

    int main() {

	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);
       
        int N;
        cin >> N;

        for (int a = 0; a < N; ++a) 
            cin >> arr[a];
        
        long ans = 0;
        

        psum[0] = arr[0];

        for (int a = 1; a < N; ++a) 
            psum[a] = psum[a - 1] + arr[a];
        

        for (int a = 0; a < N - 1; ++a) 
            ans += arr[a] * (psum[N - 1] - psum[a]);
        

        cout << ans;

        return 0;
    }

  