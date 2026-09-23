<?php
// buat kelas item
class Item {
    private string $id_Item;
    private string $nama_Item;
    private float $harga_item;
    private string $deskripsi_Item;
    private string $gambar_Item;

    // constructor default & parametrik
    public function __construct(string $id = "", string $nama = "", float $harga = 0.0, string $deskripsi = "", string $gambar = "") {
        $this->id_Item = $id;
        $this->nama_Item = $nama;
        $this->harga_item = $harga;
        $this->deskripsi_Item = $deskripsi;
        $this->gambar_Item = $gambar;
    }

    // buat setter id
    public function setId(string $id): void {
        $this->id_Item = $id;
    }

    // buat setter nama
    public function setNama(string $nama): void {
        $this->nama_Item = $nama;
    }

    // buat setter harga
    public function setHarga(float $harga): void {
        $this->harga_item = $harga;
    }

    // buat setter deskripsi
    public function setDeskripsi(string $deskripsi): void {
        $this->deskripsi_Item = $deskripsi;
    }

    // buat setter gambar
    public function setGambar(string $gambar): void {
        $this->gambar_Item = $gambar;
    }

    public function setGambar_Item(string $gambar): void {
        $this->gambar_Item = $gambar;
    }

    // buat getter id
    public function getId(): string {
        return $this->id_Item;
    }

    // buat getter nama
    public function getNama(): string {
        return $this->nama_Item;
    }

    // buat getter harga
    public function getHarga(): float {
        return $this->harga_item;
    }

    // buat getter deskripsi
    public function getDeskripsi(): string {
        return $this->deskripsi_Item;
    }

    // buat getter gambar
    public function getGambar(): string {
        return $this->gambar_Item;
    }

    public function getGambar_Item(): string {
        return $this->gambar_Item;
    }

    // buat show data item
    public function showData(): void {
        echo "ID Item        : " . $this->id_Item . "<br>";
        echo "Nama Item      : " . $this->nama_Item . "<br>";
        echo "Harga Item     : " . number_format($this->harga_item, 0, ',', '.') . " Coin<br>";
        echo "Deskripsi Item : " . $this->deskripsi_Item . "<br>";
        echo "Gambar Item    : " . $this->gambar_Item . "<br>";
    }
}
?>
