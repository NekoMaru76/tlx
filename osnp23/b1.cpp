#include <iostream>
#include <vector>
#include <algorithm>

//fastest: https://tlx.toki.id/submissions/1467124

using namespace std;

int main() {
  int nA, nB;
  cin >> nA >> nB;

  vector<int> A, B;
  int sumA = 0, sumB = 0;

  for (int i = 0; i < nA; i++) {
    int num;
    cin >> num;
    A.push_back(num);
    sumA += num;
  }

  for (int i = 0; i < nB; i++) {
    int num;
    cin >> num;
    B.push_back(num);
    sumB += num;
  }

  double avgA = (double)sumA / nA;
  double avgB = (double)sumB / nB;

  sort(B.begin(), B.end(), greater<int>());

  int result = 0;
  int largest = B[0];
  int largest_pos = 0;
  bool flag = false;

  while (!flag) {
    if (avgA > avgB) {
      flag = true;
    } else {
      result += B[largest_pos];
      sumA += B[largest_pos];
      sumB -= B[largest_pos];
      avgA = (double)sumA / (nA + 1);
      avgB = (double)sumB / (nB - 1);
      nA++;
      nB--;
      A.push_back(B[largest_pos]);
      B.erase(B.begin() + largest_pos);

      if (largest_pos > 0 && B[largest_pos - 1] > largest) {
        largest = B[largest_pos - 1];
        largest_pos--;
      }
    }
  }

  cout << result << endl;

  return 0;
}
