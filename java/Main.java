import java.util.ArrayList; // import Class ArrayList
import java.util.Locale;    // untuk Locale.US
import java.util.Scanner;   // untuk Class Scanner

public class Main {
    // kode warna ANSI subtle
    private static final String RESET  = "\033[0m";
    private static final String BOLD   = "\033[1m";
    private static final String RED    = "\033[31m";
    private static final String GREEN  = "\033[32m";
    private static final String YELLOW = "\033[33m";
    private static final String BLUE   = "\033[34m";
    private static final String CYAN   = "\033[36m";

    // buat list data dengan 5 data dummy awal
    private static ArrayList<Ball> daftarItem = new ArrayList<>();
    static {
        daftarItem.add(new Ball("I01", "Pokeball", 100.0, "Hanya Pokeball Biasa Dengan Capture Rate 1.0x", "-", "Pokeball", 0, "-", 1.0, 0));
        daftarItem.add(new Ball("T02", "Dusk Ball", 150.0, "Hanya Pokeball Dengan Capture Rate 1.0x dan 2.0x Saat Malam", "20", "Pokeball", 0, "Saat Malam 2.0x", 2.0, 0));
        daftarItem.add(new Ball("T03", "Ultra Ball", 450.0, "Pokeball Dengan Capture Rate 3.0x", "15", "Pokeball", 0, "-", 3.0, 0));
        daftarItem.add(new Ball("T04", "Beast Ball", 700.0, "Pokeball Dengan Capture Rate 1.0x dan 5.0x Saat Ingin Menangkap Ultra Beast Pokemon", "-", "Pokeball", 0, "Ultra Beast Pokemon 5.0x", 5.0, 0));
        daftarItem.add(new Ball("T05", "Master Ball", 100000.0, "Pokeball Dengan Capure Rate 100%", "-", "Pokeball", 0, "-", 1.0, 1));
    }
    private static Scanner scanner = new Scanner(System.in).useLocale(Locale.US);
    private static String bufferedInput = "";

    // helper untuk format double tanpa trailing zero berlebih
    private static String formatDouble(double val) {
        if (val == (long) val) {
            return String.format("%d", (long) val);
        } else {
            return String.format(Locale.US, "%.2f", val).replaceAll("0+$", "").replaceAll("\\.$", "");
        }
    }

    // helper untuk membuat baris berulang
    private static String repeatChar(char c, int count) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < count; i++) {
            sb.append(c);
        }
        return sb.toString();
    }

    // buat tampil awal
    private static void tampilAwal(Scanner sc) {
        System.out.println(CYAN + "\n==================================");
        System.out.println("|| Selamat Datang di PokeCenter ||");
        System.out.println("==================================" + RESET);
        System.out.print("\nTekan [Enter] untuk masuk ke menu...");
        if (sc.hasNextLine()) {
            String barisAwal = sc.nextLine().trim();
            if (!barisAwal.isEmpty()) {
                bufferedInput = barisAwal;
            }
        }
    }

    // buat cek id
    private static boolean cekId(String id) {
        for (Ball b : daftarItem) {
            if (b.getId().equalsIgnoreCase(id)) {
                return true;
            }
        }
        return false;
    }

    // buat fungsi baru cetak tabel dinamis
    public static void cetakTabel(ArrayList<Ball> daftar) {
        if (daftar.isEmpty()) {
            System.out.println(YELLOW + "\nData masih kosong bro..." + RESET);
            return;
        }

        String[] header = {
            "No", "ID", "Nama Item", "Harga", "Deskripsi", "Level Cap", "Tipe", "Is Usable", "Kondisi", "Multiplier", "Pasti Dapat"
        };

        int[] lebar = new int[header.length];
        for (int i = 0; i < header.length; i++) {
            lebar[i] = header[i].length();
        }

        for (int i = 0; i < daftar.size(); i++) {
            Ball b = daftar.get(i);
            lebar[0] = Math.max(lebar[0], String.valueOf(i + 1).length());
            lebar[1] = Math.max(lebar[1], b.getId().length());
            lebar[2] = Math.max(lebar[2], b.getNama().length());
            lebar[3] = Math.max(lebar[3], formatDouble(b.getHarga()).length());
            lebar[4] = Math.max(lebar[4], b.getDeskripsi().length());
            lebar[5] = Math.max(lebar[5], b.getLevelCap().length());
            lebar[6] = Math.max(lebar[6], b.getType().length());
            String usableStr = (b.getIsUsable() == 1) ? "1 (True)" : "0 (False)";
            lebar[7] = Math.max(lebar[7], usableStr.length());
            lebar[8] = Math.max(lebar[8], b.getKondisi_Ball().length());
            lebar[9] = Math.max(lebar[9], (formatDouble(b.getMultiplier_Ball()) + "x").length());
            String pastiStr = (b.getPastiDapet_Ball() == 1) ? "1 (Pasti)" : "0 (Tidak)";
            lebar[10] = Math.max(lebar[10], pastiStr.length());
        }

        Runnable garis = () -> {
            System.out.print(CYAN + "+");
            for (int i = 0; i < header.length; i++) {
                System.out.print(repeatChar('-', lebar[i] + 2) + "+");
            }
            System.out.println(RESET);
        };

        garis.run();
        System.out.print(CYAN + "|");
        for (int i = 0; i < header.length; i++) {
            System.out.printf(BOLD + " %-" + lebar[i] + "s " + RESET + CYAN + "|", header[i]);
        }
        System.out.println(RESET);
        garis.run();

        for (int i = 0; i < daftar.size(); i++) {
            Ball b = daftar.get(i);
            String usableStr = (b.getIsUsable() == 1) ? "1 (True)" : "0 (False)";
            String pastiStr = (b.getPastiDapet_Ball() == 1) ? "1 (Pasti)" : "0 (Tidak)";
            String[] row = {
                String.valueOf(i + 1),
                b.getId(),
                b.getNama(),
                formatDouble(b.getHarga()),
                b.getDeskripsi(),
                b.getLevelCap(),
                b.getType(),
                usableStr,
                b.getKondisi_Ball(),
                formatDouble(b.getMultiplier_Ball()) + "x",
                pastiStr
            };

            System.out.print(CYAN + "|");
            for (int j = 0; j < row.length; j++) {
                System.out.printf(" %-" + lebar[j] + "s " + CYAN + "|", row[j]);
            }
            System.out.println(RESET);
        }
        garis.run();
    }

    // buat tambah item
    private static void tambahItem(Scanner sc) {
        System.out.println(YELLOW + "\n--- Tambah Data Pokeball Baru ---" + RESET);

        String id, namaItem, deskripsi;
        double harga;

        // buat cek id
        do {
            System.out.print("[Item] ID Item              : ");
            id = sc.nextLine().trim();
            if (cekId(id)) {
                System.out.println(RED + "ID udah ada ey, ganti!" + RESET);
            }
        } while (cekId(id));

        System.out.print("[Item] Nama Item            : ");
        namaItem = sc.nextLine().trim();

        // buat cek harga
        while (true) {
            System.out.print("[Item] Harga Item           : ");
            try {
                harga = Double.parseDouble(sc.nextLine().trim());
                if (harga <= 0) {
                    System.out.println(RED + "itu harga apa utang kok mines" + RESET);
                } else {
                    break;
                }
            } catch (NumberFormatException e) {
                System.out.println(RED + "Input harga harus berupa angka!" + RESET);
            }
        }

        System.out.print("[Item] Deskripsi Item       : ");
        deskripsi = sc.nextLine().trim();

        // buat input capture device
        System.out.print("[CaptureDevice] Level Cap       : ");
        String levelCap = sc.nextLine().trim();

        System.out.print("[CaptureDevice] Tipe Device     : ");
        String typeDevice = sc.nextLine().trim();

        // buat cek is usable
        int isUsable;
        while (true) {
            System.out.print("[CaptureDevice] Is Usable (1/0) : ");
            try {
                isUsable = Integer.parseInt(sc.nextLine().trim());
                if (isUsable == 0 || isUsable == 1) {
                    break;
                }
                System.out.println(RED + "Input harus 1 (True) atau 0 (False)!" + RESET);
            } catch (NumberFormatException e) {
                System.out.println(RED + "Input harus 1 (True) atau 0 (False)!" + RESET);
            }
        }

        // buat input ball
        System.out.print("[Ball] Kondisi Ball         : ");
        String kondisiBall = sc.nextLine().trim();

        // buat cek multiplier ball
        double multiplierBall;
        while (true) {
            System.out.print("[Ball] Catch Multiplier     : ");
            try {
                multiplierBall = Double.parseDouble(sc.nextLine().trim());
                if (multiplierBall <= 0) {
                    System.out.println(RED + "Multiplier harus lebih dari 0!" + RESET);
                } else {
                    break;
                }
            } catch (NumberFormatException e) {
                System.out.println(RED + "Multiplier harus lebih dari 0!" + RESET);
            }
        }

        // buat cek pasti dapet
        int pastiDapetBall;
        while (true) {
            System.out.print("[Ball] Pasti Dapat? (1/0)   : ");
            try {
                pastiDapetBall = Integer.parseInt(sc.nextLine().trim());
                if (pastiDapetBall != 0 && pastiDapetBall != 1) {
                    System.out.println(RED + "Input harus 1 (Pasti) atau 0 (Tidak pasti)!" + RESET);
                } else {
                    break;
                }
            } catch (NumberFormatException e) {
                System.out.println(RED + "Input harus 1 (Pasti) atau 0 (Tidak pasti)!" + RESET);
            }
        }

        // buat nambah ke daftar item
        daftarItem.add(new Ball(id, namaItem, harga, deskripsi, levelCap, typeDevice, isUsable,
                                kondisiBall, multiplierBall, pastiDapetBall));

        System.out.println(GREEN + "\nPokeball berhasil ditambahkan!" + RESET);
    }

    // buat update item
    private static void updateItem(Scanner sc) {
        System.out.print("\nMasukkan ID yang mau diubah : ");
        String id = sc.nextLine().trim();

        for (int i = 0; i < daftarItem.size(); i++) {
            if (daftarItem.get(i).getId().equalsIgnoreCase(id)) {
                System.out.println(YELLOW + "\n--- Update Data (ID: " + id + ") ---" + RESET);

                // update layer 1 (item)
                System.out.print("Masukkan Nama Item Baru     : ");
                String namaItem = sc.nextLine().trim();
                daftarItem.get(i).setNama(namaItem);

                // buat cek harga
                double harga;
                while (true) {
                    System.out.print("Masukkan Harga Baru         : ");
                    try {
                        harga = Double.parseDouble(sc.nextLine().trim());
                        if (harga <= 0) {
                            System.out.println(RED + "itu harga apa utang kok mines" + RESET);
                        } else {
                            break;
                        }
                    } catch (NumberFormatException e) {
                        System.out.println(RED + "Input harga harus berupa angka!" + RESET);
                    }
                }
                daftarItem.get(i).setHarga(harga);

                System.out.print("Masukkan Deskripsi Baru     : ");
                String deskripsi = sc.nextLine().trim();
                daftarItem.get(i).setDeskripsi(deskripsi);

                // update layer 2 (capture device)
                System.out.print("Masukkan Level Cap Baru         : ");
                String levelCap = sc.nextLine().trim();
                daftarItem.get(i).setLevelCap(levelCap);

                System.out.print("Masukkan Tipe Device Baru       : ");
                String typeDevice = sc.nextLine().trim();
                daftarItem.get(i).setType(typeDevice);

                // buat cek is usable
                int isUsable;
                while (true) {
                    System.out.print("Masukkan Is Usable Baru (1/0)   : ");
                    try {
                        isUsable = Integer.parseInt(sc.nextLine().trim());
                        if (isUsable == 0 || isUsable == 1) {
                            break;
                        }
                        System.out.println(RED + "Input harus 1 (True) atau 0 (False)!" + RESET);
                    } catch (NumberFormatException e) {
                        System.out.println(RED + "Input harus 1 (True) atau 0 (False)!" + RESET);
                    }
                }
                daftarItem.get(i).setIsUsable(isUsable);

                // update layer 3 (ball)
                System.out.print("Masukkan Kondisi Ball Baru  : ");
                String kondisiBall = sc.nextLine().trim();
                daftarItem.get(i).setKondisi_Ball(kondisiBall);

                // buat cek multiplier ball
                double multiplierBall;
                while (true) {
                    System.out.print("Masukkan Multiplier Baru    : ");
                    try {
                        multiplierBall = Double.parseDouble(sc.nextLine().trim());
                        if (multiplierBall <= 0) {
                            System.out.println(RED + "Multiplier harus lebih dari 0!" + RESET);
                        } else {
                            break;
                        }
                    } catch (NumberFormatException e) {
                        System.out.println(RED + "Multiplier harus lebih dari 0!" + RESET);
                    }
                }
                daftarItem.get(i).setMultiplier_Ball(multiplierBall);

                // buat cek pasti dapet
                int pastiDapetBall;
                while (true) {
                    System.out.print("Pasti Dapat Baru (1/0)      : ");
                    try {
                        pastiDapetBall = Integer.parseInt(sc.nextLine().trim());
                        if (pastiDapetBall != 0 && pastiDapetBall != 1) {
                            System.out.println(RED + "Input harus 1 (Pasti) atau 0 (Tidak pasti)!" + RESET);
                        } else {
                            break;
                        }
                    } catch (NumberFormatException e) {
                        System.out.println(RED + "Input harus 1 (Pasti) atau 0 (Tidak pasti)!" + RESET);
                    }
                }
                daftarItem.get(i).setPastiDapet_Ball(pastiDapetBall);

                System.out.println(GREEN + "\nData Pokeball berhasil diupdate!" + RESET);
                return;
            }
        }
        System.out.println(RED + "ID gaada loh... pastiin ulang" + RESET);
    }

    // buat hapus item
    private static void hapusItem(Scanner sc) {
        System.out.print("\nID Item yang ingin dihapus : ");
        String id = sc.nextLine().trim();

        for (int i = 0; i < daftarItem.size(); i++) {
            if (daftarItem.get(i).getId().equalsIgnoreCase(id)) {
                daftarItem.remove(i);
                System.out.println(GREEN + "Data berhasil dihapus" + RESET);
                return;
            }
        }
        System.out.println(RED + "Data tidak ditemukan" + RESET);
    }

    // buat cari item
    private static void cariItem(Scanner sc) {
        System.out.print("\nID Item yang ingin dicari : ");
        String id = sc.nextLine().trim();

        for (Ball b : daftarItem) {
            if (b.getId().equalsIgnoreCase(id)) {
                System.out.println(GREEN + "\nData ditemukan!" + RESET);
                ArrayList<Ball> hasil = new ArrayList<>();
                hasil.add(b);
                cetakTabel(hasil);
                return;
            }
        }
        System.out.println(RED + "ID gaada loh... pastiin ulang" + RESET);
    }

    // buat tampil semua
    private static void tampilSemua() {
        System.out.println(CYAN + "\n=== Data Pokeball Item ===" + RESET);
        cetakTabel(daftarItem);
    }

    // buat menu item
    private static void menuItem() {
        System.out.println(CYAN + "\n==========================================");
        System.out.println("               MENU POKECENTER            ");
        System.out.println("==========================================" + RESET);
        System.out.println("1. Tambah Data Pokeball");
        System.out.println("2. Update Data Pokeball");
        System.out.println("3. Hapus Data Pokeball");
        System.out.println("4. Cari Data Pokeball");
        System.out.println("5. Tampilkan Semua Pokeball");
        System.out.println("6. Keluar");
        System.out.println(CYAN + "==========================================" + RESET);
        System.out.print("Pilihan : ");
    }

    public static void main(String[] args) {
        tampilAwal(scanner);
        int pilihan = 0;
        do {
            if (!bufferedInput.isEmpty()) {
                try {
                    pilihan = Integer.parseInt(bufferedInput);
                } catch (NumberFormatException e) {
                    pilihan = -1;
                }
                bufferedInput = "";
            } else {
                menuItem();
                if (scanner.hasNextLine()) {
                    String line = scanner.nextLine().trim();
                    try {
                        pilihan = Integer.parseInt(line);
                    } catch (NumberFormatException e) {
                        pilihan = -1;
                    }
                } else {
                    break;
                }
            }

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
                    System.out.println(GREEN + "Program selesai. Sampai jumpa di PokeCenter!" + RESET);
                    break;
                default:
                    System.out.println(RED + "Pilihan tidak ada!" + RESET);
            }
        } while (pilihan != 6);

        scanner.close();
    }
}
