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

    int arr[10001];

    bool fn(int arr[], int n) 
    {
        int i = n - 1;
        while (i > 0 && arr[i] > arr[i - 1])
            i--;

        if (i <= 0)
            return false;

        int j = n - 1;
        while (arr[i - 1] < arr[j])
            j--;

        swap(arr[i - 1], arr[j]);
        j = n - 1;
        while (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        return true;


    }




    int main() {

	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);
        int n;
        cin >> n;
        for (int a = 0; a < n; a++) 
            cin >> arr[a];
        
        if (fn(arr, n)) 
            for (int a = 0; a < n; a++) 
                cout << arr[a] << " ";
            
         
        else 
            cout << -1 << "\n";
        

        return 0;
    }

  