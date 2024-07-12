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
#define MAXX 987654321
using namespace std;


int arr[51][51];
int human;

void floid()
{

    for(int a=1;a<=human;a++)
        for (int b = 1; b <= human; b++)
            for (int c = 1; c <= human; c++)
            {
                if (arr[b][c] > arr[b][a] + arr[a][c])
                    arr[b][c] = arr[b][a] + arr[a][c];
            }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  

    cin >> human;

    for (int a = 1; a <= human; a++)
        for (int b = 1; b <= human; b++)
            arr[a][b] = MAXX;

    int pair1, pair2;
    cin >> pair1 >> pair2;
    while (pair1!=-1 && pair2!=-1)
    {
        arr[pair1][pair2] = 1;
        arr[pair2][pair1] = 1;

        cin >> pair1 >> pair2;

    }

    floid();

    int minn = MAXX;
    int cass = 0;
    vector<int>ans;
    for (int a = 1; a <= human; a++)
    {
        int min_point = 0;
        for (int b = 1; b <= human; b++)
        {
            if (a == b)
                continue;
            if (arr[a][b] == MAXX)
            {
                min_point = MAXX;
                break;
            }
            min_point = max(min_point, arr[a][b]);
        }

        if (min_point < minn)
        {
            ans.clear();
            ans.push_back(a);
            minn = min_point;
            cass = 1;
        }
        else if (min_point == minn)
        {
            ans.push_back(a);
            cass++;
        }
    }

    sort(ans.begin(), ans.end());
    cout << minn << ' ' << cass<<'\n';
    for (int a = 0; a < ans.size(); a++)
        cout << ans[a] << ' ';
}