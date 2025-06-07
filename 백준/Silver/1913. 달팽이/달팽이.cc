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

    int arr[1000][1000];



    int main() {

	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);
       
        int n, f;

        cin >> n >> f;
        int num = n * n + 1; 
        int row = 0; int col = 0; 
        int dir = 0; // 방향
        int cnt = 0; int dirCnt = 1;
        int s = n; // 방향을 바꿔야 하는 시점
        int coord[2];

        while (--num)
        {
            if (num == f)
            {
                coord[0] = row + 1; coord[1] = col + 1;
            }
            arr[row][col] = num;

            if (++cnt == s)
            {
                dir = (dir == 3 ? 0 : dir + 1);
                dirCnt++;
                cnt = 0;
            }
            if (dirCnt > 1)
            {
                s--;
                dirCnt = 0;
            }

            switch (dir)
            {
            case 0: // 하
                row++; break;
            case 1: // 우
                col++; break;
            case 2: // 상
                row--; break;
            case 3: // 좌
                col--; break;

            default: break;

            }
        }

        for (int a = 0; a < n; a++)
        {
            for (int b = 0; b < n; b++)
                cout << arr[a][b] << " ";
            cout << '\n';
        }

        cout << coord[0] << " " << coord[1];

        return 0;
    }

  