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


bool arr[1000001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, L;
   
    cin >> N >> L;

    for (int a = L; a <= 100; a++)
    {
        int tmp = (a - 1) * a / 2;
        int n = N - tmp;

        if (n < 0)
            continue;
       

        if (n % a == 0)
        {
            int start = n / a;

            while (a--)
                cout << start++ << " ";
           
            return 0;
        }
    }

    cout << -1;

    return 0;
}