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
    
    int n, k, a;
    int summ = 0;

    cin >> n >> k;
    for (a = 1; a <= k; a++) 
        summ += a;
    
    n -= summ;

    if (n < 0)
        cout << -1;
    
    else {
        if (n % k == 0)  //3)
            cout << k - 1;
        else if (n % k != 0)  //4)
            cout << k;
    }


    return 0;
}