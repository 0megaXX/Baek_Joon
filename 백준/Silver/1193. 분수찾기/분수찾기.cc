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

using namespace std;
#define MAXX 99999999



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int X;
    cin >> X;

    int a = 1;

    while (X > a)
    {
        X -= a;
        a++;
    }

    if (a % 2 == 0)
        cout << X << "/" << a - X + 1;
        
    else
        cout << a - X + 1 << "/" << X;


}

