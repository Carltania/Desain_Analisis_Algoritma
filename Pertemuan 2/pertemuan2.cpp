#include <iostream>
using namespace std;

int main() {
    const int n = 5;
    int angka[n];

    // Input bilangan
    cout << "Masukkan 5 bilangan bulat:\n";
    for (int i = 0; i < n; i++) {
        cout << "Bilangan ke-" << i + 1 << ": ";
        cin >> angka[i];
    }

    // Tampilkan bilangan sebelum diurutkan
    cout << "\nBilangan sebelum diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << angka[i] << " ";
    }
    cout << "\n\nProses pengurutan:\n";

    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        cout << "Langkah ke-" << i + 1 << ": ";
        for (int j = 0; j < n - i - 1; j++) {
            if (angka[j] > angka[j + 1]) {
                // Tukar elemen
                int temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }

        // Tampilkan hasil setelah langkah ini
        for (int k = 0; k < n; k++) {
            cout << angka[k] << " ";
        }
        cout << endl;
    }

    // Tampilkan bilangan setelah diurutkan
    cout << "\nBilangan setelah diurutkan (ascending): ";
    for (int i = 0; i < n; i++) {
        cout << angka[i] << " ";
    }
    cout << endl;

    return 0;
}
