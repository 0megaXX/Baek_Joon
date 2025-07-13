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

// 순서, 힘, 링
struct info
{
    int index;
    int power;
    int ring;
};

vector<info> v;

bool compare(info& a, info& b) // 경기력 순으로 정렬
{
    return (a.power + b.power * a.ring) > (b.power + a.power * b.ring);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    v.resize(N);
   
    for (int a = 0; a < N; a++)
    {
        int power, ring;
        cin >> power >> ring;
        v[a] = {a, power, ring};
    }

    sort(v.begin(), v.end(), compare);

    for (auto& it : v)
        cout << it.index+1 << '\n';
   

    return 0;
}
