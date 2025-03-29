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



 vector<int> v1, v2;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int t;
    cin >> t;
    while (t--) 
{
        v1.clear();
        v2.clear();

        int n, m, x;
        long long int sum = 0;
       
        cin >> n >> m;
        for (int a = 0; a < n; a++) 
        {
            cin >> x;
            v1.push_back(x);
        }
        for (int a = 0; a < m; a++) 
        {
            cin >> x;
            v2.push_back(x);
        }
        sort(v2.begin(), v2.end());

        for (int a = 0; a < n; a++) 
        {
            long long int l = 0, r = m - 1, mid;

            while (l + 1 < r) 
            {
                mid = (l + r) / 2;

                if (v2[mid] < v1[a])
                    l = mid;
                else 
                    r = mid;
            }

            sum += (abs(v1[a] - v2[l] <= abs(v1[a] - v2[r])) ? v2[l] : v2[r]);
        }

        cout << sum << '\n';
    }    return 0;
}

