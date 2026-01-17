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


set<string> Set;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    while (1)
    {
        string s;
        cin >> s;
        if (s == "*")
            break;

        bool flag = 0;
        for (int a = 1; a < s.size() && !flag; a++)
        {
            Set.clear();
            int b = 0;
            int k = b + a;
            while (!flag && k < s.size())
            {
                string tmp;
                tmp += s[b];
                tmp += s[k];
                if (!Set.empty())
                {
                    if (Set.find(tmp) != Set.end())
                    {
                        flag = 1;
                        cout << s << " is NOT surprising.\n";
                        break;
                    }
                }
                Set.insert(tmp);
                b++;
                k++;
            }
        }
        if (!flag)
            cout << s << " is surprising.\n";
        
    }

    return 0;
}