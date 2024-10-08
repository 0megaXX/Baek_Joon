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

#define MAXX 987654321
using namespace std;

int treeSize;
int ret = 0;

int tree[1<<21];

int solve(int node) 
{
    if (node * 2 >= treeSize) 
    {
        ret += tree[node];
        return tree[node];
    }
    else
    {
        int left = solve(node * 2);
        int right = solve(node * 2 + 1);
        ret += abs(left - right) + tree[node];
        return tree[node] + max(left, right);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int level;
    cin >> level;
    treeSize = 1 << (level + 1);

    for (int a = 2; a < treeSize; a++) 
        cin >> tree[a];

    solve(1);
    cout << ret << '\n';

    return 0;
}