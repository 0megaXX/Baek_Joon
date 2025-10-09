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

string FN(string x)
{
    string tmp;
    tmp = ((x[0]) - '0' * x.size()) + '0';
    return tmp;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string x;
    cin >> x;
    for (int i = 0; i < x.size(); i++)
    {
        x = FN(x);
    }
    if (x.size() == 1)
        cout << "FA" << '\n';
    else
        cout << "NFA" << '\n';

    return 0;
}