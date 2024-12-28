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


int arr[1001];

bool FindTri(int n) {
    for (int a = 1; a <= 45; a++) 
        for (int b = 1; b <= 45; b++) 
            for (int c = 1; c <= 45; c++) 
                if (arr[a] + arr[b] + arr[c] == n) 
                    return true;

    return false;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int a = 1; a <= 45; a++) 
        arr[a] = a * (a + 1) / 2;
    

    for (int a = 0; a < t; a++) {
        int num;
        cin >> num;

        cout << FindTri(num) << "\n";
    }
}
