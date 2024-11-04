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

#define MAXX 1000000000
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum1 = 0 , sum2=0;
    
    for (int a = 0; a < 4; a++)
    {
        int b;
        cin >> b;
        sum1 += b;
    }
    for (int a = 0; a < 4; a++)
    {
        int b;
        cin >> b;
        sum2 += b;
    }

    cout << max(sum1, sum2);

    return 0;
}