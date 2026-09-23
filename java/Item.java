public class Item {
    private String id_Item;
    private String nama_Item;
    private double harga_item;
    private String deskripsi_Item;

    // constructor default
    public Item() {
        this.id_Item = "";
        this.nama_Item = "";
        this.harga_item = 0.0;
        this.deskripsi_Item = "";
    }

    // constructor parametrik
    public Item(String id, String nama, double harga, String deskripsi) {
        this.id_Item = id;
        this.nama_Item = nama;
        this.harga_item = harga;
        this.deskripsi_Item = deskripsi;
    }

    // buat setter id
    public void setId(String id) {
        this.id_Item = id;
    }

    // buat setter nama
    public void setNama(String nama) {
        this.nama_Item = nama;
    }

    // buat setter harga
    public void setHarga(double harga) {
        this.harga_item = harga;
    }

    // buat setter deskripsi
    public void setDeskripsi(String deskripsi) {
        this.deskripsi_Item = deskripsi;
    }

    // buat getter id
    public String getId() {
        return this.id_Item;
    }

    // buat getter nama
    public String getNama() {
        return this.nama_Item;
    }

    // buat getter harga
    public double getHarga() {
        return this.harga_item;
    }

    // buat getter deskripsi
    public String getDeskripsi() {
        return this.deskripsi_Item;
    }

    // buat show data
    public void showData() {
        System.out.println("ID Item        : " + this.id_Item);
        System.out.println("Nama Item      : " + this.nama_Item);
        System.out.println("Harga Item     : " + String.format(java.util.Locale.US, "%.0f", this.harga_item));
        System.out.println("Deskripsi Item : " + this.deskripsi_Item);
    }
}
