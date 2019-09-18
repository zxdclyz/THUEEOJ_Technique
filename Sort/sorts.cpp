#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


/* 
* sorts function by BQSGWYS
* Usage: xSort(startPointer,endPointer) 
* to sort [startPointer,endPointer) INTERGERS by using cmp function
* Regex sort mean to sort from lower to upper
*/
bool cmp(const int& a, const int& b) { return a < b; }

void bubbleSort(int* bgn, int* end) {
  bool isLoop = true;
  for (int* i = end; isLoop && i > bgn; --i) {
    isLoop = false;
    for (int* j = bgn + 1; j < i; ++j) {
      if (cmp(*j, *(j - 1))) {
        swap(*j, *(j - 1));
        isLoop = true;
      }
    }
  }
}
void quickSort(int* bgn, int* end) {
  if (bgn >= end - 1) return;
  int *i = bgn, *j = end;
  int key = *bgn;
  while (true) {
    while (cmp(*(++i), key))
      if (i == end - 1) break;
    while (cmp(key, *(--j)))
      if (j == bgn) break;
    if (i >= j) break;
    swap(*i, *j);
  }
  swap(*bgn, *j);
  quickSort(bgn, j);
  quickSort(j + 1, end);
}

int merge(int* bgn, int* mid, int* end) {
  int* buffer = new int[end - bgn];
  int *l = bgn, *r = mid, *ptr = buffer;
  int dchance = 0;
  while (l < mid && r < end)
    if (cmp(*l, *r)) {
      *(ptr++) = *(l++);
    } else {
      dchance += mid - l;
      *(ptr++) = *(r++);
    }
  while (l < mid) *(ptr++) = *(l++);
  while (r < end) *(ptr++) = *(r++);
  l = bgn, ptr = buffer;
  while (l < end) *(l++) = *(ptr++);
  delete[] buffer;
  return dchance;
}

int mergeSort(int* bgn, int* end) {
  if (bgn >= end - 1) return 0;
  int* mid = bgn + (end - bgn) / 2;
  return mergeSort(bgn, mid) + mergeSort(mid, end) + merge(bgn, mid, end);
}

void regexSort(int* bgn, int* end) {
  size_t n = end - bgn;
  int* tmp = new int[n];
  int* count = new int[65537];
  memset(count, 0, 65537 * sizeof(int));
  for (size_t i = 0; i < n; ++i) count[(bgn[i] & 0xffff) + 1]++;
  for (size_t i = 1; i < 65536; ++i) count[i] += count[i - 1];
  for (size_t i = 0; i < n; ++i) tmp[count[bgn[i] & 0xffff]++] = bgn[i];
  memset(count, 0, 65537 * sizeof(int));
  for (size_t i = 0; i < n; ++i) count[(tmp[i] >> 16) + 1]++;
  for (size_t i = 1; i < 65536; ++i) count[i] += count[i - 1];
  for (size_t i = 0; i < n; ++i) bgn[count[tmp[i] >> 16]++] = tmp[i];
  delete[] tmp;
  delete[] count;
}

vector<int> vec;
int n, x;
int main() {
  cin >> n;
  while (n--) {
    cin >> x;
    vec.emplace_back(x);
  }
  regexSort(&(*vec.begin()), &(*vec.end()));
  for (auto num : vec) {
    cout << num << endl;
  }
  return 0;
}
