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
#define MAXX 2147483647


priority_queue<long long, vector<long long>, greater<>>pq; // 낮은거끼리 곱하는게 최소 전력 소모임

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {

        while (!pq.empty())
            pq.pop();

        int n;
        cin >> n;
        for (int a = 0; a < n; a++)
        {
            long long b;
            cin >> b;
            pq.push(b);
        }

        long long int score = 1;


        while (pq.size() != 1)
        {
            long long int one = pq.top(); pq.pop();
            long long int two = pq.top(); pq.pop();
            score *= (((one % 1000000007) * (two % 1000000007)) % 1000000007);
            pq.push(one * two);
            score %= 1000000007;

        }

        cout << score << '\n';

    }
    return 0;

}