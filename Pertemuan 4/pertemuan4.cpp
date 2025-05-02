#include <iostream>
using namespace std;

class Buku {
private:
    string judul;
    string penulis;
    int tahun_terbit;

public:
    // Constructor
    Buku() {
        cout << "Objek Buku telah dibuat." << endl;
    }

    // Destructor
    ~Buku() {
        cout << "Objek Buku '" << judul << "' telah dihapus." << endl;
    }

    // Method untuk input data
    void inputData() {
        cout << "Masukkan Judul Buku: ";
        getline(cin, judul);
        cout << "Masukkan Nama Penulis: ";
        getline(cin, penulis);
        cout << "Masukkan Tahun Terbit: ";
        cin >> tahun_terbit;
        cin.ignore(); // untuk menghindari masalah dengan getline berikutnya

        cout << "Objek Buku '" << judul << "' telah dibuat." << endl;
    }

    // Method untuk menampilkan data
    void tampilData() {
        cout << "Judul : " << judul << endl;
        cout << "Penulis : " << penulis << endl;
        cout << "Tahun Terbit : " << tahun_terbit << endl;
    }
};

int main() {
    int jumlah;

    cout << "Masukkan jumlah buku (maksimal 5): ";
    cin >> jumlah;
    cin.ignore(); // Untuk membersihkan newline di buffer

    if (jumlah < 1 || jumlah > 5) {
        cout << "Jumlah buku tidak valid. Harus antara 1 hingga 5." << endl;
        return 1;
    }

    Buku daftarBuku[5];

    cout << "\n=== Input Data Buku ===" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << "\nBuku ke-" << i + 1 << endl;
        daftarBuku[i].inputData();
    }

    cout << "\n=== Daftar Buku ===" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << "\nBuku ke-" << i + 1 << endl;
        daftarBuku[i].tampilData();
    }

    // Destructor akan otomatis dipanggil saat program selesai
    return 0;
}
