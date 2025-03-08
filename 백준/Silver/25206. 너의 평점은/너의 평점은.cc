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

    string name, grade;
    double credit;

    double sumCredit = 0.0;
    double temp;
    double res = 0.0;
    for (int a = 0; a < 20; a++) {
        cin >> name >> credit >> grade;
        if (grade == "P")
            continue;

        sumCredit += credit;
        if (grade == "F")
            continue;

        if (grade[0] == 'A') 
            temp = 4;
        else if (grade[0] == 'B')
            temp = 3;
        else if (grade[0] == 'C') 
            temp = 2;
        else temp = 1;

        if (grade[1] == '+') 
            temp += 0.5;

        res += credit * temp;
    }

    cout << res / sumCredit;
    return 0;
}

