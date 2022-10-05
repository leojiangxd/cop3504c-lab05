#include "StringData.h"
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

int linear_search(std::vector<std::string> container, std::string element)
{
    for(int i = 0; i<container.size(); i++)
        if (container[i] == element)
            return i;
    return -1;
}

int binary_search(std::vector<std::string> container, std::string element)
{
    int low = 0;
    int high = container.size() - 1;
    int mid = int((low + high) / 2);
    while (low != high)
    {
        if (container[mid] == element)
            return mid;
        else if (container[mid] < element)
        {
            low = mid + 1;
            mid = int((low + high) / 2);
        }
        else
        {
            if (mid - 1 != 0)
                high = mid - 1;
            else
                high = mid;
            mid = int((low + high) / 2);
        }
    }
    return -1;
}

int main()
{
    std::vector<std::string> stringData = getStringData();
    long long time = systemTimeNanoseconds();
    int index;
    index = linear_search(stringData, "not_here");
    time = systemTimeNanoseconds() - time;
    std::cout << "Linear (not_here); Index " << index << " in " << time / (double)1000 << " seconds\n";

    systemTimeNanoseconds();
    index = binary_search(stringData, "not_here");
    time = systemTimeNanoseconds() - time;
    std::cout << "Binary (not_here); Index " << index << " in " << time / (double)1000 << " seconds\n";

    systemTimeNanoseconds();
    index = linear_search(stringData, "mzzzz");
    time = systemTimeNanoseconds() - time;
    std::cout << "Linear (mzzzz); Index " << index << " in " << time / (double)1000 << " seconds\n";

    systemTimeNanoseconds();
    index = linear_search(stringData, "mzzzz");
    time = systemTimeNanoseconds() - time;
    std::cout << "Binary (mzzzz); Index " << index << " in " << time / (double)1000 << " seconds\n";

    systemTimeNanoseconds();
    index = linear_search(stringData, "aaaaa");
    time = systemTimeNanoseconds() - time;
    std::cout << "Linear (aaaaa); Index " << index << " in " << time / (double)1000 << " seconds\n";

    systemTimeNanoseconds();
    index = linear_search(stringData, "aaaaa");
    time = systemTimeNanoseconds() - time;
    std::cout << "Binary (aaaaa); Index " << index << " in " << time / (double)1000 << " seconds\n";

    return 0;
}



