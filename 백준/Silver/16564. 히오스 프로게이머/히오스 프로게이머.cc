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
#define MAXX 1000000001



vector<int> v;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int n;
    long long k;
    cin >> n >> k;
    v.resize(n+1);
   
    for (int a = 0; a < n; a++)
        cin >> v[a];
   
    int left = 1;
    int right = MAXX;
    int ans = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        long long sum = 0;
        for (int a = 0; a < n; a++)
            if (v[a] < mid)
                sum += mid - v[a];
 
            if (k < sum)
                right = mid - 1;
           
            else
            {
                ans = mid;
                left = mid + 1;
            }
    }
    cout << ans;

}