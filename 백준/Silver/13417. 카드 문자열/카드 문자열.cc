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

deque<char>dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cass;
    cin >> cass;
    while (cass--)
    {

        int N;
        cin >> N;
        for (int a = 0; a < N; a++)
        {
            char c;
            cin >> c;

            if (dq.empty()) // 첫 입력은 상관없음
                dq.push_back(c);

            else
            {
                if (dq.front() >= c) // 작거나 같으면 맨앞으로
                    dq.push_front(c);
                else
                    dq.push_back(c);

            }

        }

        while (!dq.empty())
        {
            cout << dq.front();
            dq.pop_front();
        }
       
        cout << '\n';
    }
   
}


