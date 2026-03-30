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


int fn(int num) 
{
    if (num <= 1) 
        return 1;
    else 
        return num * fn(num - 1);
    
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, m;
    cin >> a >> b >> c >> m;

    if (a > m) 
    {
        cout << 0;
        return 0;
    }

    int tt = 0;
    int ssum = 0;
    int rs = 0;
    while (tt < 24)
    {
        if (ssum + a > m) 
        {
            ssum -= c;
            if (ssum < 0) { ssum = 0; }
        }
        else 
        {
            ssum += a;
            rs += b;
        }
        tt++;
    }
    cout << rs;

    return 0;
}