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
#include <numeric>

using namespace std;

int arr[1001][3];
int dp[1001][3];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sizz;
    cin >> sizz; 
    for (int a = 1; a <= sizz; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            cin >> arr[a][b];

        }

    }

    for (int b = 0; b < 3; b++)
    {
        dp[1][b] = arr[1][b];
    }


    for (int a = 2; a <= sizz; a++)
    {
        
        for (int b = 0; b < 3; b++)
        {

            if (b == 0)
                dp[a][b] = min(dp[a - 1][b + 1], dp[a - 1][b + 2])+arr[a][b];

            if (b == 1)
                dp[a][b] = min(dp[a - 1][b + 1], dp[a - 1][b -1]) + arr[a][b];
            if (b == 2)
                dp[a][b] = min(dp[a - 1][b - 1], dp[a - 1][b - 2]) + arr[a][b];



        }

    }

    int minn = min(dp[sizz][0], min(dp[sizz][1], dp[sizz][2]));
    cout << minn;

}