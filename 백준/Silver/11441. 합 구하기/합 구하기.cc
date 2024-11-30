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

    int n, m;
    cin >> n;
    vector<int>v(n+2);
    for (int a = 1; a <= n; a++)
    {
        int b;
        cin >> b;
        
        v[a] = v[a - 1] + b;
    }
    

    cin >> m;

    for (int a = 0; a < m; a++)
    {
        int b, c;
        cin >> b >> c;

        cout << v[c] - v[b - 1] << '\n';


    }
}