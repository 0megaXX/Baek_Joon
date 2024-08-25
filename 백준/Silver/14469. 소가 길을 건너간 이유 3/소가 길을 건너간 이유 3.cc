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

#define MAXX 987654321
using namespace std;

vector<pair<int,int>>arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cass;
    cin >> cass;

    for (int a = 0; a < cass; a++)
    {
        int b,c;
        cin >> b>>c;
        arr.push_back({ b ,c});
    }

    sort(arr.begin(), arr.end());

    int start = 0;
    for (int a = 0; a < cass; a++)
    {
        if (start < arr[a].first)
            start = arr[a].first;
        start += arr[a].second;

        
    }
    cout << start;
}
