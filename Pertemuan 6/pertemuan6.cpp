#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // untuk transform
using namespace std;

// Fungsi untuk mengubah string menjadi huruf kecil semua
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    int n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    cin.ignore(); // untuk membersihkan newline di buffer

    vector<string> namaMahasiswa(n);

    // Input nama-nama mahasiswa
    for (int i = 0; i < n; i++) {
        cout << "Masukkan nama mahasiswa ke-" << i + 1 << ": ";
        getline(cin, namaMahasiswa[i]);
    }

    // Input nama yang ingin dicari
    string target;
    cout << "\nMasukkan nama yang ingin dicari: ";
    getline(cin, target);

    // Ubah target ke huruf kecil
    string targetLower = toLower(target);

    // Linear search
    bool ditemukan = false;
    for (int i = 0; i < n; i++) {
        if (toLower(namaMahasiswa[i]) == targetLower) {
            cout << "Nama '" << target << "' ditemukan pada indeks ke-" << i << "." << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Nama '" << target << "' tidak ditemukan dalam data." << endl;
    }

    return 0;
}
