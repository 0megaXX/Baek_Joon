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

int arr[501][501];
int N, M;



void floyd()
{
    for (int a = 1; a <= N; a++)
        for (int b = 1; b <= N; b++)
            for (int c = 1; c <= N; c++)
                if (arr[b][c] > arr[b][a] + arr[a][c])
                    arr[b][c] = arr[b][a] + arr[a][c];



}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int a = 1; a <= N; a++)
        for (int b = 1; b <= N; b++)
            arr[a][b] = MAXX;
    for (int a = 0; a < M; a++)
    {
        int fst, sec;
        cin >> fst >> sec;
        arr[fst][sec] = 1;
       // arr[sec][fst] = 1;
    }

    floyd();

   for (int a = 1; a <= N; a++)
    {
        int ct = 0;
        for (int b = 1; b <= N; b++)
        {

            if (arr[a][b] != MAXX || arr[b][a]!=MAXX)
                ct++;
        }
        cout <<N-1-ct << '\n';
    }

}