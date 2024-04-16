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

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, m;
    int count = 0;
    cin >> n >> m;

    int *arr=new int[n + 1];

    for (int a = 0; a < n; a++) {
        cin >> arr[a];
    }

    int start = 0, end = 0;
    int result = arr[0];

    while (start <= end && end < n) {
        if (result < m) {
            result += arr[++end];
        }
        else if (result == m) {
            count++;
            result += arr[++end];
        }
        else if (result > m) {
            result -= arr[start++];

            if (start > end) {
                end = start;
                result = arr[start];
            }
        }
    }

    cout << count;



}