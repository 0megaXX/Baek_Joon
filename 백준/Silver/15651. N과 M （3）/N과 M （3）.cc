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

int rs = 0;
int n, max_len;
int arr[11][11] = { 0 };
bool visit[8];

void back(int len, string s)
{
    if (len == max_len)
    {
        cout << s << '\n';
        return;
    }

    for (int a = 1; a <= n; a++)
    {
        string tmp =  s=="" ? to_string(a) : s + " " + to_string(a);
        back(len + 1, tmp);

    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> n >> max_len;

    back(0, "");

    return 0;
}