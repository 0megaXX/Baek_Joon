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
#include <regex>

using namespace std;
#define MAXX 2147483647



int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int a, b;



    cin >> a >> b;





    a--, b--;



    int aX = a / 4, aY = a % 4;
    int bX = b / 4, bY = b % 4;
    int rs = abs(aX - bX) + abs(aY - bY);



    cout << rs << "\n";


    return 0;
}