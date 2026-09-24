from Ball import Ball

# kode warna ANSI subtle
RESET  = "\033[0m"
BOLD   = "\033[1m"
RED    = "\033[31m"
GREEN  = "\033[32m"
YELLOW = "\033[33m"
BLUE   = "\033[34m"
CYAN   = "\033[36m"

# buat list data dengan 5 data dummy awal
daftarItem = [
    Ball("I01", "Pokeball", 100.0, "Hanya Pokeball Biasa Dengan Capture Rate 1.0x", "-", "Pokeball", 0, "-", 1.0, 0),
    Ball("T02", "Dusk Ball", 150.0, "Hanya Pokeball Dengan Capture Rate 1.0x dan 2.0x Saat Malam", "20", "Pokeball", 0, "Saat Malam 2.0x", 2.0, 0),
    Ball("T03", "Ultra Ball", 450.0, "Pokeball Dengan Capture Rate 3.0x", "15", "Pokeball", 0, "-", 3.0, 0),
    Ball("T04", "Beast Ball", 700.0, "Pokeball Dengan Capture Rate 1.0x dan 5.0x Saat Ingin Menangkap Ultra Beast Pokemon", "-", "Pokeball", 0, "Ultra Beast Pokemon 5.0x", 5.0, 0),
    Ball("T05", "Master Ball", 100000.0, "Pokeball Dengan Capure Rate 100%", "-", "Pokeball", 0, "-", 1.0, 1)
]
bufferedInput = ""

# helper format angka
def formatNumber(val):
    if isinstance(val, (int, float)):
        if float(val).is_integer():
            return str(int(val))
        return f"{val:.2f}".rstrip("0").rstrip(".")
    return str(val)

# buat tampil awal
def tampilAwal():
    global bufferedInput
    print(f"{CYAN}\n==================================")
    print("|| Selamat Datang di PokeCenter ||")
    print(f"=================================={RESET}")
    try:
        barisAwal = input("\nTekan [Enter] untuk masuk ke menu...").strip()
        if barisAwal:
            bufferedInput = barisAwal
    except EOFError:
        pass

# buat cek id
def cekId(id_item):
    for item in daftarItem:
        if item.getId().lower() == id_item.lower():
            return True
    return False

# buat fungsi baru cetak tabel dinamis
def cetakTabel(daftar):
    if not daftar:
        print(f"{YELLOW}\nData masih kosong bro...{RESET}")
        return

    header = [
        "No", "ID", "Nama Item", "Harga", "Deskripsi", "Level Cap", "Tipe", "Is Usable", "Kondisi", "Multiplier", "Pasti Dapat"
    ]

    lebar = [len(h) for h in header]

    for idx, b in enumerate(daftar):
        usableStr = "1 (True)" if b.getIsUsable() == 1 else "0 (False)"
        pastiStr = "1 (Pasti)" if b.getPastiDapet_Ball() == 1 else "0 (Tidak)"
        row = [
            str(idx + 1),
            b.getId(),
            b.getNama(),
            formatNumber(b.getHarga()),
            b.getDeskripsi(),
            b.getLevelCap(),
            b.getType(),
            usableStr,
            b.getKondisi_Ball(),
            formatNumber(b.getMultiplier_Ball()) + "x",
            pastiStr
        ]
        for col_idx, text in enumerate(row):
            lebar[col_idx] = max(lebar[col_idx], len(text))

    def garis():
        print(f"{CYAN}+" + "+".join(["-" * (w + 2) for w in lebar]) + f"+{RESET}")

    garis()
    header_str = f"{CYAN}|" + "|".join([f"{BOLD} {header[i]:<{lebar[i]}} {RESET}{CYAN}" for i in range(len(header))]) + f"|{RESET}"
    print(header_str)
    garis()

    for idx, b in enumerate(daftar):
        usableStr = "1 (True)" if b.getIsUsable() == 1 else "0 (False)"
        pastiStr = "1 (Pasti)" if b.getPastiDapet_Ball() == 1 else "0 (Tidak)"
        row = [
            str(idx + 1),
            b.getId(),
            b.getNama(),
            formatNumber(b.getHarga()),
            b.getDeskripsi(),
            b.getLevelCap(),
            b.getType(),
            usableStr,
            b.getKondisi_Ball(),
            formatNumber(b.getMultiplier_Ball()) + "x",
            pastiStr
        ]
        row_str = f"{CYAN}|" + "|".join([f" {row[i]:<{lebar[i]}} " for i in range(len(row))]) + f"|{RESET}"
        print(row_str)

    garis()

# buat tambah item
def tambahItem():
    print(f"{YELLOW}\n--- Tambah Data Pokeball Baru ---{RESET}")

    # buat cek id
    while True:
        id_item = input("[Item] ID Item              : ").strip()
        if cekId(id_item):
            print(f"{RED}ID udah ada ey, ganti!{RESET}")
        else:
            break

    nama_item = input("[Item] Nama Item            : ").strip()

    # buat cek harga
    while True:
        try:
            harga = float(input("[Item] Harga Item           : ").strip())
            if harga <= 0:
                print(f"{RED}itu harga apa utang kok mines{RESET}")
            else:
                break
        except ValueError:
            print(f"{RED}Input harga harus berupa angka!{RESET}")

    deskripsi = input("[Item] Deskripsi Item       : ").strip()

    # buat input capture device
    level_cap = input("[CaptureDevice] Level Cap   : ").strip()
    type_device = input("[CaptureDevice] Tipe Device : ").strip()

    # buat cek is usable
    while True:
        try:
            is_usable = int(input("[CaptureDevice] Is Usable? (1/0) : ").strip())
            if is_usable not in [0, 1]:
                print(f"{RED}Input harus 1 (True) atau 0 (False)!{RESET}")
            else:
                break
        except ValueError:
            print(f"{RED}Input harus 1 (True) atau 0 (False)!{RESET}")

    # buat input ball
    kondisi_ball = input("[Ball] Kondisi Ball         : ").strip()

    # buat cek multiplier ball
    while True:
        try:
            multiplier = float(input("[Ball] Catch Multiplier     : ").strip())
            if multiplier <= 0:
                print(f"{RED}Multiplier harus lebih dari 0!{RESET}")
            else:
                break
        except ValueError:
            print(f"{RED}Multiplier harus lebih dari 0!{RESET}")

    # buat cek pasti dapet
    while True:
        try:
            pasti_dapet = int(input("[Ball] Pasti Dapat? (1/0)   : ").strip())
            if pasti_dapet not in [0, 1]:
                print(f"{RED}Input harus 1 (Pasti) atau 0 (Tidak pasti)!{RESET}")
            else:
                break
        except ValueError:
            print(f"{RED}Input harus 1 (Pasti) atau 0 (Tidak pasti)!{RESET}")

    # buat nambah ke daftar item
    daftarItem.append(Ball(id_item, nama_item, harga, deskripsi, level_cap, type_device, is_usable,
                           kondisi_ball, multiplier, pasti_dapet))

    print(f"{GREEN}\nPokeball berhasil ditambahkan!{RESET}")

# buat update item
def updateItem():
    id_item = input("\nMasukkan ID yang mau diubah : ").strip()

    for item in daftarItem:
        if item.getId().lower() == id_item.lower():
            print(f"{YELLOW}\n--- Update Data (ID: {id_item}) ---{RESET}")

            # update layer 1 (item)
            nama_item = input("Masukkan Nama Item Baru     : ").strip()
            item.setNama(nama_item)

            # buat cek harga
            while True:
                try:
                    harga = float(input("Masukkan Harga Baru         : ").strip())
                    if harga <= 0:
                        print(f"{RED}itu harga apa utang kok mines{RESET}")
                    else:
                        break
                except ValueError:
                    print(f"{RED}Input harga harus berupa angka!{RESET}")
            item.setHarga(harga)

            deskripsi = input("Masukkan Deskripsi Baru     : ").strip()
            item.setDeskripsi(deskripsi)

            # update layer 2 (capture device)
            level_cap = input("Masukkan Level Cap Baru     : ").strip()
            item.setLevelCap(level_cap)

            type_device = input("Masukkan Tipe Device Baru   : ").strip()
            item.setType(type_device)

            # buat cek is usable
            while True:
                try:
                    is_usable = int(input("Masukkan Is Usable Baru (1/0): ").strip())
                    if is_usable not in [0, 1]:
                        print(f"{RED}Input harus 1 (True) atau 0 (False)!{RESET}")
                    else:
                        break
                except ValueError:
                    print(f"{RED}Input harus 1 (True) atau 0 (False)!{RESET}")
            item.setIsUsable(is_usable)

            # update layer 3 (ball)
            kondisi_ball = input("Masukkan Kondisi Ball Baru  : ").strip()
            item.setKondisi_Ball(kondisi_ball)

            # buat cek multiplier ball
            while True:
                try:
                    multiplier = float(input("Masukkan Multiplier Baru    : ").strip())
                    if multiplier <= 0:
                        print(f"{RED}Multiplier harus lebih dari 0!{RESET}")
                    else:
                        break
                except ValueError:
                    print(f"{RED}Multiplier harus lebih dari 0!{RESET}")
            item.setMultiplier_Ball(multiplier)

            # buat cek pasti dapet
            while True:
                try:
                    pasti_dapet = int(input("Pasti Dapat Baru (1/0)      : ").strip())
                    if pasti_dapet not in [0, 1]:
                        print(f"{RED}Input harus 1 (Pasti) atau 0 (Tidak pasti)!{RESET}")
                    else:
                        break
                except ValueError:
                    print(f"{RED}Input harus 1 (Pasti) atau 0 (Tidak pasti)!{RESET}")
            item.setPastiDapet_Ball(pasti_dapet)

            print(f"{GREEN}\nData Pokeball berhasil diupdate!{RESET}")
            return

    print(f"{RED}ID gaada loh... pastiin ulang{RESET}")

# buat hapus item
def hapusItem():
    id_item = input("\nID Item yang ingin dihapus : ").strip()

    for idx, item in enumerate(daftarItem):
        if item.getId().lower() == id_item.lower():
            del daftarItem[idx]
            print(f"{GREEN}Data berhasil dihapus{RESET}")
            return

    print(f"{RED}Data tidak ditemukan{RESET}")

# buat cari item
def cariItem():
    id_item = input("\nID Item yang ingin dicari : ").strip()

    for item in daftarItem:
        if item.getId().lower() == id_item.lower():
            print(f"{GREEN}\nData ditemukan!{RESET}")
            cetakTabel([item])
            return

    print(f"{RED}ID gaada loh... pastiin ulang{RESET}")

# buat tampil semua
def tampilSemua():
    print(f"{CYAN}\n=== Data Pokeball Item ==={RESET}")
    cetakTabel(daftarItem)

# buat menu item
def menuItem():
    print(f"{CYAN}\n==========================================")
    print("               MENU POKECENTER            ")
    print(f"=========================================={RESET}")
    print("1. Tambah Data Pokeball")
    print("2. Update Data Pokeball")
    print("3. Hapus Data Pokeball")
    print("4. Cari Data Pokeball")
    print("5. Tampilkan Semua Pokeball")
    print("6. Keluar")
    print(f"{CYAN}=========================================={RESET}")

def main():
    global bufferedInput
    tampilAwal()
    while True:
        if bufferedInput:
            pilihan = bufferedInput
            bufferedInput = ""
        else:
            menuItem()
            try:
                pilihan = input("Pilihan : ").strip()
            except EOFError:
                break

        if pilihan == "1":
            tambahItem()
        elif pilihan == "2":
            updateItem()
        elif pilihan == "3":
            hapusItem()
        elif pilihan == "4":
            cariItem()
        elif pilihan == "5":
            tampilSemua()
        elif pilihan == "6":
            print(f"{GREEN}Program selesai. Sampai jumpa di PokeCenter!{RESET}")
            break
        else:
            print(f"{RED}Pilihan tidak ada!{RESET}")

if __name__ == "__main__":
    main()
