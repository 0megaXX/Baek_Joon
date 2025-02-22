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


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int A, B, C;

    cin >> A >> B >> C;

    if ((A + B + C) != 180)
        cout << "Error\n";
    else if (A == B && B == C)
        cout << "Equilateral\n";
    else if (A == B || A == C || B == C)
        cout << "Isosceles\n";
    else
        cout << "Scalene\n";

    return 0;
}

