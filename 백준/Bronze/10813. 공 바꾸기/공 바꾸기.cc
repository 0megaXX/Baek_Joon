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

using namespace std;
#define MAXX 2147483647

int n, m;
int arr[101] = { 0, };
int a, b;

void swap(int idx1, int idx2) {
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> m;

    for (int a = 1; a <= n; a++) 
        arr[a] = a;
    

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        swap(a, b);
    }

    for (int a = 1; a <= n; a++) 
        cout << arr[a] << ' ';
    
    return 0;
}

