#include <iostream>
using namespace std;

void adjustDown(int* list, int i, int len) {
  int tmp = list[i];
  while(i*2 + 1 < len) {
    int k = i*2 + 1;
    if(k + 1 < len && list[k] > list[k + 1]) {
      k = k + 1;
    }
    if(tmp > list[k]) {
      list[i] = list[k];
      i = k;
    }else {
      break;
    }
  }
  
  list[i] = tmp;
}

void heapSort(int* list, int len) {
  //build heap, o(n)
  for(int i = len/2 -1; i >= 0; i--) {
    adjustDown(list, i, len);
  }

  //o(nlogn)
  for(int i = len -1; i > 0; i--) {
    int tmp = list[i];
    list[i] = list[0];
    list[0] = tmp;
    adjustDown(list, 0, i);
  }
}

int main() {
  int list[] = {8, 5, 0, 3, 7, 1, 2};
  heapSort(list, 7);
  for(int i = 0; i < 7; i++) {
    cout << list[i] << endl;
  }

  return 0;
}
