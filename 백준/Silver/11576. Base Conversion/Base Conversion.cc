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



int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int a_num, b_num, m;
    cin >> a_num >> b_num >> m;

    int dec= 0;
    for (int a = 0; a < m; a++)
    {
        int n;
        cin >> n;
        if (m == 1 && n == 0)
        {
            cout << "0\n";
            return 0;
        }
        dec += (n * (int)pow(a_num, m - a - 1));
    }

    stack<int> result;
    while (dec != 0)
    {
        result.push(dec % b_num);
        dec /= b_num;
    }

    while (!result.empty())
    {
        cout << result.top() << ' ';
        result.pop();
    }
    cout << '\n';


    return 0;
}