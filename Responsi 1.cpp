#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int main() {

    string username, password;
    string kode[100], nama[100];
    string teks;

    int harga[100], stok[100];
    int jumlahBarang;
    int jumlahBeli;

    double subtotal;
    double total = 0;
    double diskon = 0;
    double bayarAkhir;

    int transaksi = 0;
    int pilihan;

    ifstream baca;
    ofstream file;

    // LOGIN
    cout << "===== FAKHRI ELEKTRONIK =====" << endl;

    cout << "Username : ";
    cin >> username;

    cout << "Password : ";
    cin >> password;

    if(username == "admin" && password == "admin123") {

        do {

            cout << "\n===== MENU =====" << endl;
            cout << "1. Tambah Struk" << endl;
            cout << "2. Tampilkan Struk" << endl;
            cout << "3. Hapus Struk" << endl;
            cout << "4. Keluar" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;

            switch(pilihan) {

            case 1:

                total = 0;
                diskon = 0;

                cout << "\nJumlah Jenis Barang : ";
                cin >> jumlahBarang;

                for(int i = 0; i < jumlahBarang; i++) {

                    cout << "\nData Barang ke-" << i + 1 << endl;

                    cout << "Kode Barang : ";
                    cin >> kode[i];

                    cin.ignore();

                    cout << "Nama Barang : ";
                    getline(cin, nama[i]);

                    cout << "Harga Barang : ";
                    cin >> harga[i];

                    cout << "Stok Barang : ";
                    cin >> stok[i];

                    cout << "Jumlah Dibeli : ";
                    cin >> jumlahBeli;

                    subtotal = harga[i] * jumlahBeli;
                    total += subtotal;
                }

                // DISKON
                if(total > 500000) {
                    diskon = total * 0.10;
                }

                bayarAkhir = total - diskon;

                transaksi++;

                // SIMPAN FILE
                file.open("struk.txt");

                file << "===== FAKHRI ELEKTRONIK =====" << endl;
                file << "Total Harga : Rp " << total << endl;
                file << "Diskon      : Rp " << diskon << endl;
                file << "Bayar Akhir : Rp " << bayarAkhir << endl;
                file << "Jumlah Transaksi : " << transaksi << endl;

                file.close();

                cout << "\nStruk berhasil disimpan!" << endl;

                break;

            case 2:

                baca.open("struk.txt");

                cout << "\n===== ISI STRUK =====" << endl;

                while(getline(baca, teks)) {
                    cout << teks << endl;
                }

                baca.close();

                break;

            case 3:

                remove("struk.txt");

                cout << "\nStruk berhasil dihapus!" << endl;

                break;

            case 4:

                cout << "\nProgram selesai..." << endl;

                break;

            default:

                cout << "\nPilihan tidak tersedia!" << endl;

            }

        } while(pilihan != 4);

    } else {

        cout << "\nLogin gagal!" << endl;

    }

    return 0;
}
