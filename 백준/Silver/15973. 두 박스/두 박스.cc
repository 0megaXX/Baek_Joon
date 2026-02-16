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
    cin.tie(nullptr);

    int x1, y1, x2, y2, X1, Y1, X2, Y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> X1 >> Y1 >> X2 >> Y2;

    if (x1 > X1)
    {
        swap(x1, X1);
        swap(x2, X2);
    }

    if (y1 > Y1)
    {
        swap(y1, Y1);
        swap(y2, Y2);
    }

    if (x2 > X1 && y2 > Y1) 
        cout << "FACE";
    
    else if ((x2 == X1 && y2 > Y1) || (x2 > X1 && y2 == Y1)) 
        cout << "LINE";
    
    else if (x2 == X1 && y2 == Y1)  
        cout << "POINT";
    
    else  
        cout << "NULL";
    


    return 0;
}