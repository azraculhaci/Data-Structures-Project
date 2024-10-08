#include <iostream> 
#include <string> 
#include <fstream>
#include <vector> 
#include <cstdlib>

using namespace std;

struct takim {
    string takimAdi;
    int puan;
};

void puanSirala(vector<takim> &takimlar) {
    int n = takimlar.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (takimlar[j].puan < takimlar[j + 1].puan) {
                swap(takimlar[j], takimlar[j + 1]);
            }
        }
    }
}

int main() {
    vector<takim> takimlar;

    ifstream input("giris.txt"); 
    if (!input.is_open()) { // Dosya açılamadıysa hata mesajı verir
        cerr << "Hata! Giris dosyasi acilamadi" << endl;
        return 1;
    }

    takim t;
    while (input >> t.takimAdi) {
        string scoreStr;
        input >> scoreStr;
        t.puan = atoi(scoreStr.c_str());
        takimlar.push_back(t);
    }
    input.close(); 

    puanSirala(takimlar); // Takımları puana göre sıralar

    ofstream output("cikis.txt"); 
    if (!output.is_open()) { // Dosya açılamadıysa hata mesajı verir
        cerr << "Hata! Cikis dosyasi acilamadi" << endl;
        return 1;
    }

  for (int i = 0; i < takimlar.size(); i++) {
    // Sıralı takımları çıkış dosyasına ve terminale yazdır
    cout << (i + 1) << " " << takimlar[i].takimAdi << " " << takimlar[i].puan << endl;
    output << (i + 1) << " " << takimlar[i].takimAdi << " " << takimlar[i].puan << endl;
}

    output.close(); 
    system("pause"); 

    return 0;
}
