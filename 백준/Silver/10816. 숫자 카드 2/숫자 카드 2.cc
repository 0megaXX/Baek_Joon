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
using namespace std;





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int original_count;
    cin >> original_count;
    vector<int> original_arr(original_count);
    for (int a = 0; a < original_count; a++)
        cin >> original_arr[a];

    sort(original_arr.begin(), original_arr.end());

    int user_count;
    cin >> user_count;
    vector<int> user_arr(user_count);
    for (int a = 0; a < user_count; a++)
        cin >> user_arr[a];

    for (int a = 0; a < user_count; a++) {
        int count = upper_bound(original_arr.begin(), original_arr.end(), user_arr[a]) - lower_bound(original_arr.begin(), original_arr.end(), user_arr[a]);
        cout << count << " ";
    }
}