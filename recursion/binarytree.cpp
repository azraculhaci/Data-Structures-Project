#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Özyineli ikili arama fonksiyonu
// Önkoşul: list.size() == Listedeki öğe sayısı
// Sonkoşul: Anahtar kelimenin listedeki dizinini döndürür, anahtar kelime 
// bulunamadıysa -1 döndürür
int binarySearchRecursive(const vector<string> &list, const string &key, int low, int high) {
  if (low > high) {
    return -1;  // Anahtar kelime bulunamadı
  } else {
    int mid = (low + high) / 2;

    if (list[mid] == key) {
      return mid;  // Anahtar kelime bulundu
    } else if (list[mid] < key) {
      return binarySearchRecursive(list, key, mid + 1, high);  // Anahtar kelime üst yarındadır
    } else {
      return binarySearchRecursive(list, key, low, mid - 1);  // Anahtar kelime alt yarındadır
    }
  }
}

int main() {
  vector<string> list = {"elma", "armut", "kiraz", "üzüm","muz", "portakal"};
  string key = "muz";
  int index = binarySearchRecursive(list, key, 0, list.size() - 1);

  if (index == -1) {
    cout << "Anahtar kelime bulunamadı." << endl;
  } else {
    cout << "Anahtar kelime '" << key << "' dizinin " << index << ". indisinde." << endl;
  }

  return 0;
}
