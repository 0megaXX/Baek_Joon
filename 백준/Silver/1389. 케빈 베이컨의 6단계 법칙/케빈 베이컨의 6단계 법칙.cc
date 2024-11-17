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


int arr[101][101];
int N, M;

void floyd() //플로이드 워셜
{

    for (int a = 1; a <= N; a++)
        for (int b = 1; b <= N; b++)
            for (int c = 1; c <= N; c++)
                if (arr[b][c] > arr[b][a] + arr[a][c])
                    arr[b][c] = arr[b][a] + arr[a][c];

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> M;

    for (int a = 1; a <= N; a++)
        for (int b = 1; b <= N; b++)
            if (a != b)
                arr[a][b] = MAXX;

    for (int a = 0; a < M; a++)
    {
        int start, end;
        cin >> start >> end;
        arr[start][end] = 1;
        arr[end][start] = 1;
    }

    floyd();

    int minn = MAXX;
    int rs = 0;
    for (int a = 1; a <= N; a++)
    {
        int temp = 0; // a의 케빈 베이컨

        for (int b = 1; b <= N; b++)
            temp += arr[a][b];


        if (temp < minn) // 케빈 베이컨 갱신 가능시
        {
            minn = temp;
            rs = a;
        }
    }

    cout << rs;
    return 0;
}


  