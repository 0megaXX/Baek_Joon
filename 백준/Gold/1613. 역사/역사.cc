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
#define MAXX 98765432
using namespace std;

int history[501][501];
int n, k;



void floyd()
{
    for (int a = 1; a <= n; a++)
        for (int b = 1; b <= n; b++)
            for (int c = 1; c <= n; c++)
                if (history[b][c] > history[b][a] + history[a][c])
                    history[b][c] = history[b][a] + history[a][c];



}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> n >> k;
    for (int a = 1; a <= n; a++)
        for (int b = 1; b <= n; b++)
            history[a][b] = MAXX;
    for (int a = 0; a < k; a++)
    {
        int fst, sec;
        cin >> fst >> sec;
        history[fst][sec] = 1;

    }

    floyd();
    
    int q;
    cin >> q;
    while (q--)
    {
        int fst, sec;
        cin >> fst >> sec;
        if (history[fst][sec] == MAXX&& history[sec][fst] == MAXX)
            cout << 0 << '\n';
        else if (history[fst][sec] < history[sec][fst])
            cout << -1 << '\n';
        else
            cout << 1 << '\n';
    }
}