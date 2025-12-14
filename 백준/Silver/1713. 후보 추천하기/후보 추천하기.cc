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

int  arr[101];
vector<int> rs;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, num;
    bool bl;
    cin >> N >> M;

    vector<pair<int, int>> v(N);
 

    for (int a = 0; a < M; a++)
    {
        cin >> num;
        arr[num]++;
        bl = false;
        for (int b = 0; b < N; b++)
        {
            if (v[b].first == 0)
            {
                v[b].first = num;
                v[b].second = a;
                bl = true;
                break;
            }
            else if (v[b].first == num)
            {
                bl = true;
                break;
            }
        }
        if (!bl)
        {
            int index = 0;
            for (int b = 1; b < N; b++)
            {
                if (arr[v[index].first] > arr[v[b].first])
                    index = b;
                else if (arr[v[index].first] == arr[v[b].first])
                {
                    if (v[index].second > v[b].second)
                        index = b;
                }
            }
            arr[v[index].first] = 0;
            v[index].first = num;
            v[index].second = a;
        }
    }
    for (int a = 0; a < N; a++)
        rs.push_back(v[a].first);

    sort(rs.begin(), rs.end());

    for (int a = 0; a < rs.size(); a++)
        if (rs[a] != 0)
            cout << rs[a] << ' ';
    

    return 0;
}