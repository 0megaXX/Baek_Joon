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


      vector<vector<int>> accSum;

    int main() {

	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);
        int r, c, q;
  
        
        cin >> r >> c >> q;
        accSum = vector<vector<int>>(r + 1, vector<int>(c + 1, 0));
        for (int a = 1; a <= r; a++)
        {
            int sum = 0;
            for (int b = 1; b <= c; b++) 
            {
                int k;
                cin >> k;
                sum += k;
                accSum[a][b] = sum;
            }
        }
        for (int a = 0; a < q; a++) 
        {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            int cnt = (r2 - r1 + 1) * (c2 - c1 + 1);
            int sum = 0;
            for (int b = r1; b <= r2; b++) 
                sum += accSum[b][c2] - accSum[b][c1 - 1];
            
            cout << sum / cnt << "\n";
        }

        return 0;
    }

 