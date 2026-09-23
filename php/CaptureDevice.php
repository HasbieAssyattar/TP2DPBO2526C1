<?php
require_once 'Item.php';

// buat kelas capture device
class CaptureDevice extends Item {
    private string $levelCap_CaptureDevice; // buat level cap device
    private string $type_CaptureDevice;     // buat tipe device

    // constructor default & parametrik
    public function __construct(
        string $id = "",
        string $nama = "",
        float $harga = 0.0,
        string $deskripsi = "",
        string $gambar = "",
        string $levelCap = "",
        string $type = ""
    ) {
        parent::__construct($id, $nama, $harga, $deskripsi, $gambar);
        $this->levelCap_CaptureDevice = $levelCap;
        $this->type_CaptureDevice = $type;
    }

    // buat setter level cap
    public function setLevelCap_CaptureDevice(string $levelCap): void {
        $this->levelCap_CaptureDevice = $levelCap;
    }

    public function setLevelCap(string $levelCap): void {
        $this->levelCap_CaptureDevice = $levelCap;
    }

    // buat setter type device
    public function setType_CaptureDevice(string $type): void {
        $this->type_CaptureDevice = $type;
    }

    public function setType(string $type): void {
        $this->type_CaptureDevice = $type;
    }

    // buat getter level cap
    public function getLevelCap_CaptureDevice(): string {
        return $this->levelCap_CaptureDevice;
    }

    public function getLevelCap(): string {
        return $this->levelCap_CaptureDevice;
    }

    // buat getter type device
    public function getType_CaptureDevice(): string {
        return $this->type_CaptureDevice;
    }

    public function getType(): string {
        return $this->type_CaptureDevice;
    }

    // buat show data capture device
    public function showDataCaptureDevice(): void {
        echo "Level Cap Device   : " . $this->levelCap_CaptureDevice . "<br>";
        echo "Type Device        : " . $this->type_CaptureDevice . "<br>";
    }
}
?>
