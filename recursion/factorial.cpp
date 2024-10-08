#include <iostream>
using namespace std;
typedef long long BigInt;

BigInt RecFactorial(int num) {
  if (0 == num) {
    return 1;
  } else {
    return num * RecFactorial(num - 1);
  }
}





int main() {
  int num;
  cout << "Bir sayi giriniz: ";
  cin >> num;

  cout << num << "! = " << RecFactorial(num) << endl;

  return 0;
}
