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

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int len;
    cin >> len;
    char c;
    for (int a = 0; a < len; a++)
    {
        cin >> c;
        if (c >= 97)// 소문자면
            cout << "L";
        else // 대문자면
            cout << "i";

    }
    return 0;
}