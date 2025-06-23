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
	long long arr[100005];

    int main() {

	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);
       
		
		long long n, q, x, y;
		cin >> n;
		for (int a = 0; a < n; a++)
		{
			cin >> arr[a];
			if (a != 0) 
			{
				if (arr[a - 1] > arr[a])
					arr[a - 1] = 1;
				else
					arr[a - 1] = 0;
			}
		}
		for (int a = 1; a < n; a++) 
			arr[a] += arr[a - 1];
		


		cin >> q;
		long long ct = 0;
		for (int a = 0; a < q; a++)
		{
			ct = 0;
			cin >> x >> y;
			if (x >= 2 && y >= 2)
				cout << arr[y - 2] - arr[x - 2] << "\n";
			else if (y == 1)
				cout << 0 << "\n";
			else
				cout << arr[y - 2] << "\n";
		}
        return 0;
    }

  