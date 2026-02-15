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

vector<char> v;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    int num1 = 1, num2;

    cin >> k;

    while (num1 < k)
        num1 *= 2;

    int tmp = num1, ct = 0;
    while (k != 0)
    {
        if (k >= tmp)
        {
            num2 = ct;
            k -= tmp;
        }
        tmp /= 2;
        ct++;
    }

    cout << num1 << " " << num2;
    

    return 0;
}