//
// Created by Leo on 10/5/2022.
//

#include <StringData>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

int linear_search(std::vector<std::string> container, std::string element)
{
    for(i = 0; i<container.length(); i++)
        if (container[i] == element)
            return i;
    return -1;
}

int binary_search(std::vector<std::string> container, std::string element)
{
    int low = 0;
    high = container.length() - 1;
    while(high>=low)
    {
        mid = int(high+low);
        if (container[mid] < element)
            low = mid + 1;
        else if (container[mid] > element)
            high = mid - 1;
        else
            return mid;
        return -1;
    }
}

int main()
{
    std::vector<std::string> stringData = StringData.getStringData();
    long currentTime = systemTimeNanoseconds();
    std::string element;
    cin >> element;
    int index = linear_search(stringData, element);
    currentTime = systemTimeNanoseconds() - currentTime;
    cout << "linear " << element << "found in "<< currentTime << " seconds at index " << index

    index = binary_search(stringData, element);
    currentTime = systemTimeNanoseconds() - currentTime;
    cout << "linear " << element << "found in "<< currentTime << " seconds at index " << index
    return 0;
}



