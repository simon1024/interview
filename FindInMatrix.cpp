#include <iostream>
#include <vector>

using namespace std;

/**
题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
1 2 8  9 
n2 4 9  12
4 7 10 13
6 8 11 15
*/

bool find(int target, int* matrix, int lineNum, int columnNum) {
    int i = 0; 
    int j = columnNum - 1;

    while(i < lineNum && j >= 0) {
        int value = *(matrix + columnNum * i + j);
        cout << "value:" << value << " pos:" << columnNum * i + j << endl;
        if(value == target) {
            cout << "i,j: " <<i << "," << j << endl;
            return true;
        }else if (value < target) {
            i++;
        }else{
            j--;
        }
    }

    return false;
}

int main() {
    int matrix[][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    bool ret = find(7, (int*)matrix, 4, 4);
    cout << "result: " << ret << endl; 

    return 0;
}
