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

vector<int>original;
vector<int>lis;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    original.resize(n);
    for (int a = 0; a < n; a++)
        cin >> original[a];

    
    lis.push_back(original[0]);
    for (int a = 1; a < n; a++)
    {
        if (original[a] > lis[lis.size() - 1])
            lis.push_back(original[a]);

        else  // lis중 현재 값보다 작은 수 중 가장 근사한 값과을 대체
        {
            int pos = lower_bound(lis.begin(), lis.end(), original[a])-lis.begin();      
            lis[pos] = original[a];
        }

    }


    cout << lis.size();


    return 0;
}