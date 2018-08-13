#include <iostream>
using namespace std;

void merge(int* a, int lenA, int* b, int lenB) {
  int i = 0;
  int j = 0;
  int k = 0;

  int* tmp = new int[lenA + lenB];
  while(i < lenA && j < lenB) {
    if(a[i] <= b[j]) {
      tmp[k++] = a[i++];
    }else {
      tmp[k++] = b[j++];
    }
  }
  
}
