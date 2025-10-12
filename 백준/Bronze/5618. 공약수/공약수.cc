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

int fn(int a, int b)
{
    if (b == 0) { return a; }
    return fn(b, a % b);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, a, b, c, g;
    cin >> n;
    if (n == 2)
    {
        cin >> a >> b;
        g = fn(a, b);
        for (int a = 1; a <= g; a++)
            if (g % a == 0)
                cout << a << '\n';
    }
    else
    {
        cin >> a >> b >> c;
        g = fn(a, fn(b, c));
        for (int a = 1; a <= g; a++)
            if (g % a == 0)
                cout << a << '\n';
    }

    return 0;
}