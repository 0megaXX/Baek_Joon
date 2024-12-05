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

    int M, N, min = 0, sum = 0;
    cin >> M >> N;

    // 1부터 i*i가 N보다 작거나 같을 때까지
    for (int a = 1; a * a <= N; a++)
        if (a * a >= M)
        {
            sum += a * a;
            if (min == 0) // 최소값
                min = a * a;
        }
   

    if (sum == 0)
        cout << "-1\n";
    else
        cout << sum << "\n" << min << "\n";
}