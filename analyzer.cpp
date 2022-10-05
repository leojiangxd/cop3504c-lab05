#include <iostream>
#include <vector>
#include <string>
#include "StringData.h"

using namespace std;

int linear_search(vector<string> container, string element){
    for (int i = 0; i < container.size(); i++) {
        if (container[i] == element)
            return i;
    }
    return -1;
}

int binary_search(vector<string> container, string element){
    int low = 0;
    int high = container.size() - 1;
    int mid = (low + high) / 2;

    while (low != high){
        if (container[mid] == element)
            return mid;
        else if (container[mid] < element){
            low = mid + 1;
            mid = (low + high) / 2;
        }
        else {
            if (mid - 1 != 0)
                high = mid - 1;
            else
                high = mid;
            mid = (low + high) / 2;
        }
    }
    return -1;
}

int main(){
    vector<string> data = getStringData(); 
    long long start, end;
    int res;
    cout << "\n";

    // testing linear and binary search for string "not_here"
    cout << "Testing for string \"not_here\"\n";
    start = systemTimeNanoseconds();
    res = linear_search(data, "not_here");
    end = systemTimeNanoseconds();
    cout << "Linear returned " << res << " in " << (end - start) / (double)1000 << " seconds\n";
    
    start = systemTimeNanoseconds();
    res = binary_search(data, "not_here");
    end = systemTimeNanoseconds();
    cout << "Binary returned " << res << " in " << (end - start) / (double)1000 << " seconds\n";

    cout << "\n";

    // testing linear and binary search for string "mzzzz"
    cout << "Testing for string \"mzzzz\"\n";
    start = systemTimeNanoseconds();
    res = linear_search(data, "mzzzz");
    end = systemTimeNanoseconds();
    cout << "Linear returned " << res << " in " << (end - start) / (double)1000 << " seconds\n";
    
    start = systemTimeNanoseconds();
    res = binary_search(data, "mzzzz");
    end = systemTimeNanoseconds();
    cout << "Binary returned " << res << " in " << (end - start) / (double)1000 << " seconds\n";

    cout << "\n";

    // testing linear and binary search for string "aaaaa"
    cout << "Testing for string \"aaaaa\"\n";
    start = systemTimeNanoseconds();
    res = linear_search(data, "aaaaa");
    end = systemTimeNanoseconds();
    cout << "Linear returned " << res << " in " << (end - start) / (double)1000 << " seconds\n";
    
    start = systemTimeNanoseconds();
    res = binary_search(data, "aaaaa");
    end = systemTimeNanoseconds();
    cout << "Binary returned " << res << " in " << (end - start) / (double)1000 << " seconds\n";

    cout << "\n";

    return 0;
}
