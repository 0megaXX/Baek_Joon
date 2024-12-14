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

using namespace std;
#define MAXX 99999999


int arr[501][501];


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, b;
    cin >> n >> m >> b;

    int ans = MAXX;
    int ansHeight = -1;

    for (int a = 0; a < n; a++) 
        for (int b = 0; b < m; b++) 
            cin >> arr[a][b];
        
    



    for (int h = 0; h <= 256; h++) {
        int inven = 0;
        int remove = 0;

        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++)
            {
                int minus = arr[a][b] - h;

                if (minus < 0) 
                    inven -= minus;
                
                else if (minus > 0) 
                    remove += minus;
                
            }
        }

        if (remove + b >= inven) 
        {
            int ct = (2 * remove) + inven;

            if (ans >= ct)
            {
                ans = ct;
                ansHeight = h;
            }
        }
    }

    cout << ans << " " << ansHeight;
}
