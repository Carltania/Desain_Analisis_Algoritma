#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    float nilai;
};

// Fungsi untuk menampilkan data mahasiswa
void tampilkanData(Mahasiswa arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nama : " << arr[i].nama << ", Nilai : " << arr[i].nilai << endl;
    }
}

// Fungsi merge untuk merge sort
void merge(Mahasiswa arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Mahasiswa* L = new Mahasiswa[n1];
    Mahasiswa* R = new Mahasiswa[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Urutkan secara descending
    while (i < n1 && j < n2) {
        if (L[i].nilai >= R[j].nilai) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Sisipkan sisa data
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

// Fungsi rekursif merge sort
void mergeSort(Mahasiswa arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    Mahasiswa* data = new Mahasiswa[n];

    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << ":\n";
        cout << "Nama  : ";
        cin >> ws; // Menghindari masalah input string
        getline(cin, data[i].nama);
        cout << "Nilai : ";
        cin >> data[i].nilai;
    }

    cout << "\nData sebelum diurutkan:\n";
    tampilkanData(data, n);

    mergeSort(data, 0, n - 1);

    cout << "\nData setelah diurutkan (descending):\n";
    tampilkanData(data, n);

    delete[] data;
    return 0;
}
