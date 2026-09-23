// Program PokeCenter - Multi-Layer Inheritance: Item -> CaptureDevice -> Ball
#include "Ball.cpp"
#include <bits/stdc++.h>

using namespace std;

// List penampung objek Ball (daun dari multi layer inheritance: Item -> CaptureDevice -> Ball)
vector<Ball> daftarItem;

// Fungsi menampilkan salam pembuka (menunggu tombol Enter sebelum masuk ke menu)
void tampilAwal() {
    cout << "\n==================================" << endl;
    cout << "|| Selamat Datang di PokeCenter ||" << endl;
    cout << "==================================" << endl;
    cout << "\nTekan [Enter] untuk masuk ke menu...";
    cin.get();
}

// Mengecek apakah ID item sudah ada di dalam list (unik)
bool cekId(const string& id) {
    for (int i = 0; i < daftarItem.size(); i++) {
        if (daftarItem[i].getId() == id) {
            return true;
        }
    }
    return false;
}

// 1. CREATE: Tambah Data Item (Multi-layer: Item -> CaptureDevice -> Ball)
void tambahItem() {
    cout << "\n--- Tambah Data Pokeball Baru ---" << endl;
    
    // --- Layer 1: Atribut dari kelas Item (ID, Nama, Harga, Deskripsi) ---
    string id, namaItem, deskripsi;
    double harga;

    // Input ID dengan validasi keunikan
    do {
        cout << "[Item] ID Item              : ";
        cin >> id;
        if (cekId(id)) {
            cout << "ID udah ada ey, ganti!" << endl;
        }
    } while (cekId(id));

    cout << "[Item] Nama Item            : ";
    getline(cin >> ws, namaItem);

    // Input Harga dengan validasi > 0
    do {
        cout << "[Item] Harga Item           : ";
        cin >> harga;
        if (harga <= 0) {
            cout << "itu harga apa utang kok mines" << endl;
        }
    } while (harga <= 0);

    cout << "[Item] Deskripsi Item       : ";
    getline(cin >> ws, deskripsi);

    // --- Layer 2: Atribut dari kelas CaptureDevice (levelCap bertipe string bebas) ---
    string levelCap, typeDevice;

    cout << "[CaptureDevice] Level Cap   : ";
    getline(cin >> ws, levelCap);

    cout << "[CaptureDevice] Tipe Device : ";
    getline(cin >> ws, typeDevice);

    // --- Layer 3: Atribut dari kelas Ball (Kondisi, Multiplier, Pasti Dapet) ---
    string kondisiBall;
    double multiplierBall;
    int pastiDapetBall;

    cout << "[Ball] Kondisi Ball         : ";
    getline(cin >> ws, kondisiBall);

    do {
        cout << "[Ball] Catch Multiplier     : ";
        cin >> multiplierBall;
        if (multiplierBall <= 0) {
            cout << "Multiplier harus lebih dari 0!" << endl;
        }
    } while (multiplierBall <= 0);

    do {
        cout << "[Ball] Pasti Dapat? (1/0)   : ";
        cin >> pastiDapetBall;
        if (pastiDapetBall != 0 && pastiDapetBall != 1) {
            cout << "Input harus 1 (Pasti) atau 0 (Tidak pasti)!" << endl;
        }
    } while (pastiDapetBall != 0 && pastiDapetBall != 1);

    // Instansiasi objek Ball melalui multi-layer inheritance (tanpa namaBall dan foto)
    daftarItem.push_back(Ball(id, namaItem, harga, deskripsi, levelCap, typeDevice,
                              kondisiBall, multiplierBall, pastiDapetBall));

    cout << "\nPokeball berhasil ditambahkan!" << endl;
}

// 2. UPDATE: Mengubah data item berdasarkan ID
void updateItem() {
    string id;
    cout << "\nMasukkan ID yang mau diubah : ";
    cin >> id;

    for (auto &i : daftarItem) {
        if (i.getId() == id) {
            cout << "\n--- Update Data (ID: " << id << ") ---" << endl;

            // Update Layer 1 (Item)
            string namaItem, deskripsi;
            double harga;

            cout << "Masukkan Nama Item Baru     : ";
            getline(cin >> ws, namaItem);
            i.setNama(namaItem);

            do {
                cout << "Masukkan Harga Baru         : ";
                cin >> harga;
                if (harga <= 0) {
                    cout << "itu harga apa utang kok mines" << endl;
                }
            } while (harga <= 0);
            i.setHarga(harga);

            cout << "Masukkan Deskripsi Baru     : ";
            getline(cin >> ws, deskripsi);
            i.setDeskripsi(deskripsi);

            // Update Layer 2 (CaptureDevice)
            string levelCap, typeDevice;

            cout << "Masukkan Level Cap Baru     : ";
            getline(cin >> ws, levelCap);
            i.setLevelCap(levelCap);

            cout << "Masukkan Tipe Device Baru   : ";
            getline(cin >> ws, typeDevice);
            i.setType(typeDevice);

            // Update Layer 3 (Ball - tanpa namaBall)
            string kondisiBall;
            double multiplierBall;
            int pastiDapetBall;

            cout << "Masukkan Kondisi Ball Baru  : ";
            getline(cin >> ws, kondisiBall);
            i.setKondisi_Ball(kondisiBall);

            do {
                cout << "Masukkan Multiplier Baru    : ";
                cin >> multiplierBall;
                if (multiplierBall <= 0) {
                    cout << "Multiplier harus lebih dari 0!" << endl;
                }
            } while (multiplierBall <= 0);
            i.setMultiplier_Ball(multiplierBall);

            do {
                cout << "Pasti Dapat Baru (1/0)      : ";
                cin >> pastiDapetBall;
                if (pastiDapetBall != 0 && pastiDapetBall != 1) {
                    cout << "Input harus 1 (Pasti) atau 0 (Tidak pasti)!" << endl;
                }
            } while (pastiDapetBall != 0 && pastiDapetBall != 1);
            i.setPastiDapet_Ball(pastiDapetBall);

            cout << "\nData Pokeball berhasil diupdate!" << endl;
            return;
        }
    }
    cout << "ID gaada loh... pastiin ulang" << endl;
}

// 3. DELETE: Menghapus data item berdasarkan ID
void hapusItem() {
    string id;
    cout << "\nID Item yang ingin dihapus : ";
    cin >> id;

    for (auto it = daftarItem.begin(); it != daftarItem.end(); ++it) {
        if (it->getId() == id) {
            daftarItem.erase(it);
            cout << "Data berhasil dihapus" << endl;
            return;
        }
    }
    cout << "Data tidak ditemukan" << endl;
}

// 4. READ (CARI): Mencari item berdasarkan ID
void cariItem() {
    string id;
    cout << "\nID Item yang ingin dicari : ";
    cin >> id;

    for (const auto &i : daftarItem) {
        if (i.getId() == id) {
            cout << "\nData ditemukan!" << endl;
            i.showData();
            return;
        }
    }
    cout << "ID gaada loh... pastiin ulang" << endl;
}

// 5. READ (TAMPILKAN SEMUA): Menampilkan seluruh data item
void tampilSemua() {
    cout << "\n=== Data Pokeball Item ===" << endl;
    if (daftarItem.empty()) {
        cout << "Data masih kosong bro..." << endl;
        return;
    }

    for (int idx = 0; idx < daftarItem.size(); idx++) {
        cout << "\n[ Data ke-" << (idx + 1) << " ]" << endl;
        daftarItem[idx].showData();
    }
}

// Tampilan menu navigasi
void menuItem() {
    cout << "\n==========================================" << endl;
    cout << "               MENU POKECENTER            " << endl;
    cout << "==========================================" << endl;
    cout << "1. Tambah Data Pokeball" << endl;
    cout << "2. Update Data Pokeball" << endl;
    cout << "3. Hapus Data Pokeball" << endl;
    cout << "4. Cari Data Pokeball" << endl;
    cout << "5. Tampilkan Semua Pokeball" << endl;
    cout << "6. Keluar" << endl;
    cout << "==========================================" << endl;
    cout << "Pilihan : ";
}

int main() {
    tampilAwal();
    int pilihan;
    do {
        menuItem();
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                tambahItem();
                break;
            case 2:
                updateItem();
                break;
            case 3:
                hapusItem();
                break;
            case 4:
                cariItem();
                break;
            case 5:
                tampilSemua();
                break;
            case 6:
                cout << "Program selesai. Sampai jumpa di PokeCenter!" << endl;
                exit(0);
                break;
            default:
                cout << "Pilihan tidak ada!" << endl;
        }
    } while (pilihan != 6);

    return 0;
}
