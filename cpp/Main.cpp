#include "Ball.cpp"
#include <bits/stdc++.h>

using namespace std;

// kode warna ANSI subtle
const string RESET   = "\033[0m";
const string BOLD    = "\033[1m";
const string RED     = "\033[31m";
const string GREEN   = "\033[32m";
const string YELLOW  = "\033[33m";
const string BLUE    = "\033[34m";
const string CYAN    = "\033[36m";

// buat list data dengan 5 data dummy awal
vector<Ball> daftarItem = {
  Ball("I01", "Pokeball", 100.0, "Hanya Pokeball Biasa Dengan Capture Rate 1.0x", "-", "Pokeball", 0, "-", 1.0, 0),
  Ball("T02", "Dusk Ball", 150.0, "Hanya Pokeball Dengan Capture Rate 1.0x dan 2.0x Saat Malam", "20", "Pokeball", 0, "Saat Malam 2.0x", 2.0, 0),
  Ball("T03", "Ultra Ball", 450.0, "Pokeball Dengan Capture Rate 3.0x", "15", "Pokeball", 0, "-", 3.0, 0),
  Ball("T04", "Beast Ball", 700.0, "Pokeball Dengan Capture Rate 1.0x dan 5.0x Saat Ingin Menangkap Ultra Beast Pokemon", "-", "Pokeball", 0, "Ultra Beast Pokemon 5.0x", 5.0, 0),
  Ball("T05", "Master Ball", 100000.0, "Pokeball Dengan Capure Rate 100%", "-", "Pokeball", 0, "-", 1.0, 1)
};
string bufferedInput = "";

// buat tampil awal
void tampilAwal() {
  cout << CYAN << "\n==================================" << endl;
  cout << "|| Selamat Datang di PokeCenter ||" << endl;
  cout << "==================================" << RESET << endl;
  cout << "\nTekan [Enter] untuk masuk ke menu...";
  string barisAwal;
  if (getline(cin, barisAwal)) {
    // jika user langsung input nomor menu (misal piping dari file)
    size_t nonWs = barisAwal.find_first_not_of(" \t\r\n");
    if (nonWs != string::npos) {
      bufferedInput = barisAwal.substr(nonWs);
    }
  }
}

// buat cek id
bool cekId(const string &id) {
  for (int i = 0; i < daftarItem.size(); i++) {
    if (daftarItem[i].getId() == id) {
      return true;
    }
  }
  return false;
}

// buat fungsi baru cetak tabel dinamis
void cetakTabel(const vector<Ball>& daftar) {
  if (daftar.empty()) {
    cout << YELLOW << "\nData masih kosong bro..." << RESET << endl;
    return;
  }

  vector<string> header = {
    "No", "ID", "Nama Item", "Harga", "Deskripsi", "Level Cap", "Tipe", "Is Usable", "Kondisi", "Multiplier", "Pasti Dapat"
  };

  vector<int> lebar(header.size(), 0);
  for (int i = 0; i < header.size(); i++) {
    lebar[i] = header[i].length();
  }

  auto formatDouble = [](double val) {
    ostringstream oss;
    oss << fixed << setprecision(2) << val;
    string s = oss.str();
    if (s.find('.') != string::npos) {
      while (s.back() == '0') s.pop_back();
      if (s.back() == '.') s.pop_back();
    }
    return s;
  };

  for (size_t i = 0; i < daftar.size(); i++) {
    const auto& b = daftar[i];
    lebar[0] = max(lebar[0], (int)to_string(i + 1).length());
    lebar[1] = max(lebar[1], (int)b.getId().length());
    lebar[2] = max(lebar[2], (int)b.getNama().length());
    lebar[3] = max(lebar[3], (int)formatDouble(b.getHarga()).length());
    lebar[4] = max(lebar[4], (int)b.getDeskripsi().length());
    lebar[5] = max(lebar[5], (int)b.getLevelCap().length());
    lebar[6] = max(lebar[6], (int)b.getType().length());
    string usableStr = (b.getIsUsable() == 1) ? "1 (True)" : "0 (False)";
    lebar[7] = max(lebar[7], (int)usableStr.length());
    lebar[8] = max(lebar[8], (int)b.getKondisi_Ball().length());
    lebar[9] = max(lebar[9], (int)(formatDouble(b.getMultiplier_Ball()) + "x").length());
    string pastiStr = (b.getPastiDapet_Ball() == 1) ? "1 (Pasti)" : "0 (Tidak)";
    lebar[10] = max(lebar[10], (int)pastiStr.length());
  }

  auto garis = [&]() {
    cout << CYAN << "+";
    for (int i = 0; i < header.size(); i++) {
      cout << string(lebar[i] + 2, '-') << "+";
    }
    cout << RESET << "\n";
  };

  garis();
  cout << CYAN << "|";
  for (int i = 0; i < header.size(); i++) {
    cout << BOLD << " " << header[i] << string(lebar[i] - header[i].length() + 1, ' ') << RESET << CYAN << "|";
  }
  cout << RESET << "\n";
  garis();

  for (size_t i = 0; i < daftar.size(); i++) {
    const auto& b = daftar[i];
    string noStr = to_string(i + 1);
    string idStr = b.getId();
    string namaStr = b.getNama();
    string hargaStr = formatDouble(b.getHarga());
    string deskStr = b.getDeskripsi();
    string lvlStr = b.getLevelCap();
    string tipeStr = b.getType();
    string usableStr = (b.getIsUsable() == 1) ? "1 (True)" : "0 (False)";
    string kondisiStr = b.getKondisi_Ball();
    string multStr = formatDouble(b.getMultiplier_Ball()) + "x";
    string pastiStr = (b.getPastiDapet_Ball() == 1) ? "1 (Pasti)" : "0 (Tidak)";

    vector<string> baris = {noStr, idStr, namaStr, hargaStr, deskStr, lvlStr, tipeStr, usableStr, kondisiStr, multStr, pastiStr};

    cout << CYAN << "|";
    for (int j = 0; j < baris.size(); j++) {
      cout << " " << baris[j] << string(lebar[j] - baris[j].length() + 1, ' ') << CYAN << "|";
    }
    cout << RESET << "\n";
  }
  garis();
}

// buat tambah item
void tambahItem() {
  cout << YELLOW << "\n--- Tambah Data Pokeball Baru ---" << RESET << endl;

  string id, namaItem, deskripsi;
  double harga;

  // buat cek id
  do {
    cout << "[Item] ID Item              : ";
    cin >> id;
    if (cekId(id)) {
      cout << RED << "ID udah ada ey, ganti!" << RESET << endl;
    }
  } while (cekId(id));

  cout << "[Item] Nama Item            : ";
  getline(cin >> ws, namaItem);

  // buat cek harga
  do {
    cout << "[Item] Harga Item           : ";
    cin >> harga;
    if (harga <= 0) {
      cout << RED << "itu harga apa utang kok mines" << RESET << endl;
    }
  } while (harga <= 0);

  cout << "[Item] Deskripsi Item       : ";
  getline(cin >> ws, deskripsi);

  // buat input capture device
  string levelCap, typeDevice;
  int isUsable;

  cout << "[CaptureDevice] Level Cap       : ";
  getline(cin >> ws, levelCap);

  cout << "[CaptureDevice] Tipe Device     : ";
  getline(cin >> ws, typeDevice);

  // buat cek is usable
  do {
    cout << "[CaptureDevice] Is Usable (1/0) : ";
    cin >> isUsable;
    if (isUsable != 0 && isUsable != 1) {
      cout << RED << "Input harus 1 (True) atau 0 (False)!" << RESET << endl;
    }
  } while (isUsable != 0 && isUsable != 1);

  // buat input ball
  string kondisiBall;
  double multiplierBall;
  int pastiDapetBall;

  cout << "[Ball] Kondisi Ball         : ";
  getline(cin >> ws, kondisiBall);

  // buat cek multiplier ball
  do {
    cout << "[Ball] Catch Multiplier     : ";
    cin >> multiplierBall;
    if (multiplierBall <= 0) {
      cout << RED << "Multiplier harus lebih dari 0!" << RESET << endl;
    }
  } while (multiplierBall <= 0);

  // buat cek pasti dapet
  do {
    cout << "[Ball] Pasti Dapat? (1/0)   : ";
    cin >> pastiDapetBall;
    if (pastiDapetBall != 0 && pastiDapetBall != 1) {
      cout << RED << "Input harus 1 (Pasti) atau 0 (Tidak pasti)!" << RESET << endl;
    }
  } while (pastiDapetBall != 0 && pastiDapetBall != 1);

  // buat nambah ke daftar item
  daftarItem.push_back(Ball(id, namaItem, harga, deskripsi, levelCap,
                            typeDevice, isUsable, kondisiBall, multiplierBall,
                            pastiDapetBall));

  cout << GREEN << "\nPokeball berhasil ditambahkan!" << RESET << endl;
}

// buat update item
void updateItem() {
  string id;
  cout << "\nMasukkan ID yang mau diubah : ";
  cin >> id;

  for (auto &i : daftarItem) {
    if (i.getId() == id) {
      cout << YELLOW << "\n--- Update Data (ID: " << id << ") ---" << RESET << endl;

      string namaItem, deskripsi;
      double harga;

      cout << "Masukkan Nama Item Baru     : ";
      getline(cin >> ws, namaItem);
      i.setNama(namaItem);

      // buat cek harga
      do {
        cout << "Masukkan Harga Baru         : ";
        cin >> harga;
        if (harga <= 0) {
          cout << RED << "itu harga apa utang kok mines" << RESET << endl;
        }
      } while (harga <= 0);
      i.setHarga(harga);

      cout << "Masukkan Deskripsi Baru     : ";
      getline(cin >> ws, deskripsi);
      i.setDeskripsi(deskripsi);

      // buat input capture device
      string levelCap, typeDevice;
      int isUsable;

      cout << "Masukkan Level Cap Baru         : ";
      getline(cin >> ws, levelCap);
      i.setLevelCap(levelCap);

      cout << "Masukkan Tipe Device Baru       : ";
      getline(cin >> ws, typeDevice);
      i.setType(typeDevice);

      // buat cek is usable
      do {
        cout << "Masukkan Is Usable Baru (1/0)   : ";
        cin >> isUsable;
        if (isUsable != 0 && isUsable != 1) {
          cout << RED << "Input harus 1 (True) atau 0 (False)!" << RESET << endl;
        }
      } while (isUsable != 0 && isUsable != 1);
      i.setIsUsable(isUsable);

      // buat input ball
      string kondisiBall;
      double multiplierBall;
      int pastiDapetBall;

      cout << "Masukkan Kondisi Ball Baru  : ";
      getline(cin >> ws, kondisiBall);
      i.setKondisi_Ball(kondisiBall);

      // buat cek multiplier ball
      do {
        cout << "Masukkan Multiplier Baru    : ";
        cin >> multiplierBall;
        if (multiplierBall <= 0) {
          cout << RED << "Multiplier harus lebih dari 0!" << RESET << endl;
        }
      } while (multiplierBall <= 0);
      i.setMultiplier_Ball(multiplierBall);

      // buat cek pasti dapet
      do {
        cout << "Pasti Dapat Baru (1/0)      : ";
        cin >> pastiDapetBall;
        if (pastiDapetBall != 0 && pastiDapetBall != 1) {
          cout << RED << "Input harus 1 (Pasti) atau 0 (Tidak pasti)!" << RESET << endl;
        }
      } while (pastiDapetBall != 0 && pastiDapetBall != 1);
      i.setPastiDapet_Ball(pastiDapetBall);

      cout << GREEN << "\nData Pokeball berhasil diupdate!" << RESET << endl;
      return;
    }
  }
  cout << RED << "ID gaada loh... pastiin ulang" << RESET << endl;
}

// buat hapus item
void hapusItem() {
  string id;
  cout << "\nID Item yang ingin dihapus : ";
  cin >> id;

  for (auto it = daftarItem.begin(); it != daftarItem.end(); ++it) {
    if (it->getId() == id) {
      daftarItem.erase(it);
      cout << GREEN << "Data berhasil dihapus" << RESET << endl;
      return;
    }
  }
  cout << RED << "Data tidak ditemukan" << RESET << endl;
}

// buat cari item
void cariItem() {
  string id;
  cout << "\nID Item yang ingin dicari : ";
  cin >> id;

  for (const auto &i : daftarItem) {
    if (i.getId() == id) {
      cout << GREEN << "\nData ditemukan!" << RESET << endl;
      vector<Ball> hasil = {i};
      cetakTabel(hasil);
      return;
    }
  }
  cout << RED << "ID gaada loh... pastiin ulang" << RESET << endl;
}

// buat tampil semua
void tampilSemua() {
  cout << CYAN << "\n=== Data Pokeball Item ===" << RESET << endl;
  cetakTabel(daftarItem);
}

// buat menu item
void menuItem() {
  cout << CYAN << "\n==========================================" << endl;
  cout << "               MENU POKECENTER            " << endl;
  cout << "==========================================" << RESET << endl;
  cout << "1. Tambah Data Pokeball" << endl;
  cout << "2. Update Data Pokeball" << endl;
  cout << "3. Hapus Data Pokeball" << endl;
  cout << "4. Cari Data Pokeball" << endl;
  cout << "5. Tampilkan Semua Pokeball" << endl;
  cout << "6. Keluar" << endl;
  cout << CYAN << "==========================================" << RESET << endl;
  cout << "Pilihan : ";
}

int main() {
  tampilAwal();
  int pilihan;
  do {
    if (!bufferedInput.empty()) {
      try {
        pilihan = stoi(bufferedInput);
      } catch (...) {
        pilihan = -1;
      }
      bufferedInput = "";
    } else {
      menuItem();
      if (!(cin >> pilihan)) break;
    }

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
      cout << GREEN << "Program selesai. Sampai jumpa di PokeCenter!" << RESET << endl;
      exit(0);
      break;
    default:
      cout << RED << "Pilihan tidak ada!" << RESET << endl;
    }
  } while (pilihan != 6);

  return 0;
}
