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



long long fn(int i)
{
    if (!i)
        return 1;
    long long temp = fn(i / 2);

    if (i % 2)
        return temp * temp * 3;
    return temp * temp;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, rs=0;

    cin >> n;
    for (int a = 0; a < 40; ++a)
        if (n & (1LL << a))
            rs += fn(a);

    cout << rs;

    return 0;
}