from Ball import Ball

# buat list data
daftarItem = []

# buat tampil awal
def tampilAwal():
    print("\n==================================")
    print("|| Selamat Datang di PokeCenter ||")
    print("==================================")
    input("\nTekan [Enter] untuk masuk ke menu...")

# buat cek id
def cekId(id_item):
    for item in daftarItem:
        if item.getId() == id_item:
            return True
    return False

# buat tambah item
def tambahItem():
    print("\n--- Tambah Data Pokeball Baru ---")

    # buat cek id
    while True:
        id_item = input("[Item] ID Item              : ")
        if cekId(id_item):
            print("ID udah ada ey, ganti!")
        else:
            break

    nama_item = input("[Item] Nama Item            : ")

    # buat cek harga
    while True:
        try:
            harga = float(input("[Item] Harga Item           : "))
            if harga <= 0:
                print("itu harga apa utang kok mines")
            else:
                break
        except ValueError:
            print("Input harga harus berupa angka!")

    deskripsi = input("[Item] Deskripsi Item       : ")

    # buat input capture device
    level_cap = input("[CaptureDevice] Level Cap   : ")
    type_device = input("[CaptureDevice] Tipe Device : ")

    # buat input ball
    kondisi_ball = input("[Ball] Kondisi Ball         : ")

    # buat cek multiplier ball
    while True:
        try:
            multiplier = float(input("[Ball] Catch Multiplier     : "))
            if multiplier <= 0:
                print("Multiplier harus lebih dari 0!")
            else:
                break
        except ValueError:
            print("Multiplier harus lebih dari 0!")

    # buat cek pasti dapet
    while True:
        try:
            pasti_dapet = int(input("[Ball] Pasti Dapat? (1/0)   : "))
            if pasti_dapet not in [0, 1]:
                print("Input harus 1 (Pasti) atau 0 (Tidak pasti)!")
            else:
                break
        except ValueError:
            print("Input harus 1 (Pasti) atau 0 (Tidak pasti)!")

    # buat nambah ke daftar item
    daftarItem.append(Ball(id_item, nama_item, harga, deskripsi, level_cap, type_device,
                           kondisi_ball, multiplier, pasti_dapet))

    print("\nPokeball berhasil ditambahkan!")

# buat update item
def updateItem():
    id_item = input("\nMasukkan ID yang mau diubah : ")

    for item in daftarItem:
        if item.getId() == id_item:
            print(f"\n--- Update Data (ID: {id_item}) ---")

            # update layer 1 (item)
            nama_item = input("Masukkan Nama Item Baru     : ")
            item.setNama(nama_item)

            # buat cek harga
            while True:
                try:
                    harga = float(input("Masukkan Harga Baru         : "))
                    if harga <= 0:
                        print("itu harga apa utang kok mines")
                    else:
                        break
                except ValueError:
                    print("Input harga harus berupa angka!")
            item.setHarga(harga)

            deskripsi = input("Masukkan Deskripsi Baru     : ")
            item.setDeskripsi(deskripsi)

            # update layer 2 (capture device)
            level_cap = input("Masukkan Level Cap Baru     : ")
            item.setLevelCap(level_cap)

            type_device = input("Masukkan Tipe Device Baru   : ")
            item.setType(type_device)

            # update layer 3 (ball)
            kondisi_ball = input("Masukkan Kondisi Ball Baru  : ")
            item.setKondisi_Ball(kondisi_ball)

            # buat cek multiplier ball
            while True:
                try:
                    multiplier = float(input("Masukkan Multiplier Baru    : "))
                    if multiplier <= 0:
                        print("Multiplier harus lebih dari 0!")
                    else:
                        break
                except ValueError:
                    print("Multiplier harus lebih dari 0!")
            item.setMultiplier_Ball(multiplier)

            # buat cek pasti dapet
            while True:
                try:
                    pasti_dapet = int(input("Pasti Dapat Baru (1/0)      : "))
                    if pasti_dapet not in [0, 1]:
                        print("Input harus 1 (Pasti) atau 0 (Tidak pasti)!")
                    else:
                        break
                except ValueError:
                    print("Input harus 1 (Pasti) atau 0 (Tidak pasti)!")
            item.setPastiDapet_Ball(pasti_dapet)

            print("\nData Pokeball berhasil diupdate!")
            return

    print("ID gaada loh... pastiin ulang")

# buat hapus item
def hapusItem():
    id_item = input("\nID Item yang ingin dihapus : ")

    for item in daftarItem:
        if item.getId() == id_item:
            daftarItem.remove(item)
            print("Data berhasil dihapus")
            return

    print("Data tidak ditemukan")

# buat cari item
def cariItem():
    id_item = input("\nID Item yang ingin dicari : ")

    for item in daftarItem:
        if item.getId() == id_item:
            print("\nData ditemukan!")
            item.showData()
            return

    print("ID gaada loh... pastiin ulang")

# buat tampil semua
def tampilSemua():
    print("\n=== Data Pokeball Item ===")
    if not daftarItem:
        print("Data masih kosong bro...")
        return

    for idx, item in enumerate(daftarItem):
        print(f"\n[ Data ke-{idx + 1} ]")
        item.showData()

# buat menu item
def menuItem():
    print("\n==========================================")
    print("               MENU POKECENTER            ")
    print("==========================================")
    print("1. Tambah Data Pokeball")
    print("2. Update Data Pokeball")
    print("3. Hapus Data Pokeball")
    print("4. Cari Data Pokeball")
    print("5. Tampilkan Semua Pokeball")
    print("6. Keluar")
    print("==========================================")

def main():
    tampilAwal()
    while True:
        menuItem()
        pilihan = input("Pilihan : ")
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
            print("Program selesai. Sampai jumpa di PokeCenter!")
            break
        else:
            print("Pilihan tidak ada!")

if __name__ == "__main__":
    main()
