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


    int triangle[3];

    vector<int>v(1001);
    int main() {

	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);

        while (1)
        {
            for (int a = 0; a < 3; a++)
                cin >> triangle[a];

            if (triangle[0] == 0 && triangle[0] == triangle[1] && triangle[0] == triangle[2])
                break;
            
            sort(triangle, triangle + 3);
            if (triangle[2] >= triangle[1] + triangle[0])
                cout << "Invalid" << '\n';
            
            else if (triangle[0] != triangle[1] && triangle[1] != triangle[2] && triangle[0] != triangle[2])         
                cout << "Scalene" << '\n';
            
            else
            
                if (triangle[0] == triangle[1] && triangle[1] == triangle[2])
                {
                    cout << "Equilateral" << '\n';
                }
                else
                    cout << "Isosceles" << '\n';
            
        }
        return 0;
    }

  