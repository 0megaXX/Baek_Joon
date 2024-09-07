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

vector<int>v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cass;
    cin >> cass;
    for (int a = 0; a < cass; a++)
    {
        int b;
        cin >> b;
        v.push_back(b);
    }
    sort(v.begin(), v.end());
    int rs = 0;
    int tmp;
    while ( next_permutation(v.begin(), v.end()) ) 
    {
        tmp = 0;
        for (int a = 0; a < v.size() - 1; a++) 
            tmp += abs(v[a] - v[a + 1]);
        


        rs = max(rs, tmp);
    }

    cout << rs;

}
