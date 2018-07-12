#include <iostream>
using namespace std;

int binarySearch(int* list, int begin, int end, int value) {
  if(begin > end) {
    return -1;
  }

  int middle = (begin + end)/2;
  if(list[middle] == value) {
    return middle;
  }

  if(list[middle] < value) {
    return binarySearch(list, middle + 1, end, value);
  }else {
    return binarySearch(list, begin, middle - 1, value);
  }
}

int main() {
  int list[] = {2,4,6,8,10,12,14,16};
  cout << binarySearch(list, 0, 7, 12) << endl;
  cout << binarySearch(list, 0, 7, 2) << endl;
  cout << binarySearch(list, 0, 7, 16) << endl;
  cout << binarySearch(list, 0, 7, 18) << endl;
  cout << binarySearch(list, 0, 7, 1) << endl;

  return 0;
}
