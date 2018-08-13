#include <iostream>
#include <vector>

using namespace std;

/**
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
For example, given the array [2,3,-2,4], the contiguous subarray [2,3] has the largest product = 6.
*/


struct SubArray {
    int begin;
    int end;
    int product;
    SubArray(int b, int e, int p) {
        begin = b;
        end = e ;
        product = p;
    }
};

SubArray findMaxSubArray(vector<int> array) {
    if(array.size() == 0) {
        return SubArray(-1, -1, 0);
    }

    vector<SubArray> minList, maxList;
    minList.reserve(array.size());
    maxList.reserve(array.size());

    minList[0] = SubArray(0, 0, array[0]);
    maxList[0] = SubArray(0, 0, array[0]);
    int maxIdx = 0;
    for(size_t i = 1; i < array.size(); ++i) {
        if(array[i] >= 0) {
            if(array[i] > array[i] * maxList[i - 1].product) {
                maxList[i] = SubArray(i, i, array[i]);
            }else {
                maxList[i] = SubArray(maxList[i - 1].begin, i, array[i] * maxList[i - 1].product);
            }

            if(array[i] < array[i] * minList[i - 1].product) {
                minList[i] = SubArray(i, i, array[i]);
            }else {
                minList[i] = SubArray(minList[i - 1].begin, i, array[i] * minList[i - 1].product);
            }
        }else {
            if(array[i] > array[i] * minList[i - 1].product) {
                maxList[i] = SubArray(i, i, array[i]);
            }else {
                maxList[i] = SubArray(minList[i - 1].begin, i, array[i] * minList[i - 1].product);
            }

            if(array[i] < array[i] * maxList[i - 1].product) {
                minList[i] = SubArray(i, i, array[i]);
            }else {
                minList[i] = SubArray(maxList[i - 1].begin, i, array[i] * maxList[i - 1].product);
            }
        }

        if(maxList[maxIdx].product < maxList[i].product) {
            maxIdx = i;
        }
        
    }

    return maxList[maxIdx];
}

int main() {

    {
        int a[] = {2, 3, -2, 4};
        vector<int> array(a, a+4);
        SubArray result = findMaxSubArray(array);
        if(result.begin != -1) {
            cout << "begin:" << result.begin << " end:" << result.end << endl;
            cout << "max product:" << result.product << endl;
        }
    }

    {
        int a[] = {2, 3, -2, 4, -1};
        vector<int> array(a, a+5);
        SubArray result = findMaxSubArray(array);
        if(result.begin != -1) {
            cout << "begin:" << result.begin << " end:" << result.end << endl;
            cout << "max product:" << result.product << endl;
        }
    }
    return 0;
}
