import java.util.ArrayList; // import Class ArrayList
import java.util.Locale;    // untuk Locale.US
import java.util.Scanner;   // untuk Class Scanner

public class Main {
    // buat list data
    private static ArrayList<Ball> daftarItem = new ArrayList<>();
    private static Scanner scanner = new Scanner(System.in).useLocale(Locale.US);

    // buat tampil awal
    private static void tampilAwal(Scanner sc) {
        System.out.println("\n==================================");
        System.out.println("|| Selamat Datang di PokeCenter ||");
        System.out.println("==================================");
        System.out.print("\nTekan [Enter] untuk masuk ke menu...");
        sc.nextLine();
    }

    // buat cek id
    private static boolean cekId(String id) {
        for (Ball b : daftarItem) {
            if (b.getId().equals(id)) {
                return true;
            }
        }
        return false;
    }

    // buat tambah item
    private static void tambahItem(Scanner sc) {
        System.out.println("\n--- Tambah Data Pokeball Baru ---");

        // buat input item
        String id, namaItem, deskripsi;
        double harga;

        // buat cek id
        do {
            System.out.print("[Item] ID Item              : ");
            id = sc.nextLine();
            if (cekId(id)) {
                System.out.println("ID udah ada ey, ganti!");
            }
        } while (cekId(id));

        System.out.print("[Item] Nama Item            : ");
        namaItem = sc.nextLine();

        // buat cek harga
        do {
            System.out.print("[Item] Harga Item           : ");
            harga = sc.nextDouble();
            sc.nextLine(); // membersihkan buffer
            if (harga <= 0) {
                System.out.println("itu harga apa utang kok mines");
            }
        } while (harga <= 0);

        System.out.print("[Item] Deskripsi Item       : ");
        deskripsi = sc.nextLine();

        // buat input capture device
        String levelCap, typeDevice;

        System.out.print("[CaptureDevice] Level Cap   : ");
        levelCap = sc.nextLine();

        System.out.print("[CaptureDevice] Tipe Device : ");
        typeDevice = sc.nextLine();

        // buat input ball
        String kondisiBall;
        double multiplierBall;
        int pastiDapetBall;

        System.out.print("[Ball] Kondisi Ball         : ");
        kondisiBall = sc.nextLine();

        // buat cek multiplier ball
        do {
            System.out.print("[Ball] Catch Multiplier     : ");
            multiplierBall = sc.nextDouble();
            sc.nextLine(); // membersihkan buffer
            if (multiplierBall <= 0) {
                System.out.println("Multiplier harus lebih dari 0!");
            }
        } while (multiplierBall <= 0);

        // buat cek pasti dapet
        do {
            System.out.print("[Ball] Pasti Dapat? (1/0)   : ");
            pastiDapetBall = sc.nextInt();
            sc.nextLine(); // membersihkan buffer
            if (pastiDapetBall != 0 && pastiDapetBall != 1) {
                System.out.println("Input harus 1 (Pasti) atau 0 (Tidak pasti)!");
            }
        } while (pastiDapetBall != 0 && pastiDapetBall != 1);

        // buat nambah ke daftar item
        daftarItem.add(new Ball(id, namaItem, harga, deskripsi, levelCap, typeDevice,
                                kondisiBall, multiplierBall, pastiDapetBall));

        System.out.println("\nPokeball berhasil ditambahkan!");
    }

    // buat update item
    private static void updateItem(Scanner sc) {
        String id;
        System.out.print("\nMasukkan ID yang mau diubah : ");
        id = sc.nextLine();

        for (int i = 0; i < daftarItem.size(); i++) {
            if (daftarItem.get(i).getId().equals(id)) {
                System.out.println("\n--- Update Data (ID: " + id + ") ---");

                // update layer 1 (item)
                System.out.print("Masukkan Nama Item Baru     : ");
                String namaItem = sc.nextLine();
                daftarItem.get(i).setNama(namaItem);

                // buat cek harga
                double harga;
                do {
                    System.out.print("Masukkan Harga Baru         : ");
                    harga = sc.nextDouble();
                    sc.nextLine(); // membersihkan buffer
                    if (harga <= 0) {
                        System.out.println("itu harga apa utang kok mines");
                    }
                } while (harga <= 0);
                daftarItem.get(i).setHarga(harga);

                System.out.print("Masukkan Deskripsi Baru     : ");
                String deskripsi = sc.nextLine();
                daftarItem.get(i).setDeskripsi(deskripsi);

                // update layer 2 (capture device)
                System.out.print("Masukkan Level Cap Baru     : ");
                String levelCap = sc.nextLine();
                daftarItem.get(i).setLevelCap(levelCap);

                System.out.print("Masukkan Tipe Device Baru   : ");
                String typeDevice = sc.nextLine();
                daftarItem.get(i).setType(typeDevice);

                // update layer 3 (ball)
                System.out.print("Masukkan Kondisi Ball Baru  : ");
                String kondisiBall = sc.nextLine();
                daftarItem.get(i).setKondisi_Ball(kondisiBall);

                // buat cek multiplier ball
                double multiplierBall;
                do {
                    System.out.print("Masukkan Multiplier Baru    : ");
                    multiplierBall = sc.nextDouble();
                    sc.nextLine(); // membersihkan buffer
                    if (multiplierBall <= 0) {
                        System.out.println("Multiplier harus lebih dari 0!");
                    }
                } while (multiplierBall <= 0);
                daftarItem.get(i).setMultiplier_Ball(multiplierBall);

                // buat cek pasti dapet
                int pastiDapetBall;
                do {
                    System.out.print("Pasti Dapat Baru (1/0)      : ");
                    pastiDapetBall = sc.nextInt();
                    sc.nextLine(); // membersihkan buffer
                    if (pastiDapetBall != 0 && pastiDapetBall != 1) {
                        System.out.println("Input harus 1 (Pasti) atau 0 (Tidak pasti)!");
                    }
                } while (pastiDapetBall != 0 && pastiDapetBall != 1);
                daftarItem.get(i).setPastiDapet_Ball(pastiDapetBall);

                System.out.println("\nData Pokeball berhasil diupdate!");
                return;
            }
        }
        System.out.println("ID gaada loh... pastiin ulang");
    }

    // buat hapus item
    private static void hapusItem(Scanner sc) {
        String id;
        System.out.print("\nID Item yang ingin dihapus : ");
        id = sc.nextLine();

        // buat hapus item
        for (int i = 0; i < daftarItem.size(); i++) {
            if (daftarItem.get(i).getId().equals(id)) {
                daftarItem.remove(i);
                System.out.println("Data berhasil dihapus");
                return;
            }
        }
        System.out.println("Data tidak ditemukan");
    }

    // buat cari item
    private static void cariItem(Scanner sc) {
        String id;
        System.out.print("\nID Item yang ingin dicari : ");
        id = sc.nextLine();

        // buat cari item
        for (Ball b : daftarItem) {
            if (b.getId().equals(id)) {
                System.out.println("\nData ditemukan!");
                b.showData();
                return;
            }
        }
        System.out.println("ID gaada loh... pastiin ulang");
    }

    // buat tampil semua
    private static void tampilSemua() {
        System.out.println("\n=== Data Pokeball Item ===");
        if (daftarItem.isEmpty()) {
            System.out.println("Data masih kosong bro...");
            return;
        }

        for (int idx = 0; idx < daftarItem.size(); idx++) {
            System.out.println("\n[ Data ke-" + (idx + 1) + " ]");
            daftarItem.get(idx).showData();
        }
    }

    // buat menu item
    private static void menuItem() {
        System.out.println("\n==========================================");
        System.out.println("               MENU POKECENTER            ");
        System.out.println("==========================================");
        System.out.println("1. Tambah Data Pokeball");
        System.out.println("2. Update Data Pokeball");
        System.out.println("3. Hapus Data Pokeball");
        System.out.println("4. Cari Data Pokeball");
        System.out.println("5. Tampilkan Semua Pokeball");
        System.out.println("6. Keluar");
        System.out.println("==========================================");
        System.out.print("Pilihan : ");
    }

    public static void main(String[] args) {
        tampilAwal(scanner);
        int pilihan;
        do {
            menuItem();
            pilihan = scanner.nextInt();
            scanner.nextLine(); // membersihkan buffer

            switch (pilihan) {
                case 1:
                    tambahItem(scanner);
                    break;
                case 2:
                    updateItem(scanner);
                    break;
                case 3:
                    hapusItem(scanner);
                    break;
                case 4:
                    cariItem(scanner);
                    break;
                case 5:
                    tampilSemua();
                    break;
                case 6:
                    System.out.println("Program selesai. Sampai jumpa di PokeCenter!");
                    break;
                default:
                    System.out.println("Pilihan tidak ada!");
            }
        } while (pilihan != 6);

        scanner.close();
    }
}
