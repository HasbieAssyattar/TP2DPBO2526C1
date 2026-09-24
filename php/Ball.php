<?php
require_once 'CaptureDevice.php';

// buat kelas ball
class Ball extends CaptureDevice {
    private string $kondisi_Ball;    // buat nambah kondisi ball
    private float $multiplier_Ball;  // buat nambah multiplier ball
    private int $pastiDapet_Ball;    // buat nambah pasti dapet ball

    // constructor default & parametrik
    public function __construct(
        string $id = "",
        string $nama = "",
        float $harga = 0.0,
        string $deskripsi = "",
        string $gambar = "",
        string $levelCap = "",
        string $type = "",
        int $isUsable = 0,
        string $kondisi = "",
        float $multiplier = 0.0,
        int $pastiDapet = 0
    ) {
        parent::__construct($id, $nama, $harga, $deskripsi, $gambar, $levelCap, $type, $isUsable);
        $this->kondisi_Ball = $kondisi;
        $this->multiplier_Ball = $multiplier;
        $this->pastiDapet_Ball = $pastiDapet;
    }

    // buat setter kondisi ball
    public function setKondisi_Ball(string $kondisi): void {
        $this->kondisi_Ball = $kondisi;
    }

    public function setKondisiBall(string $kondisi): void {
        $this->kondisi_Ball = $kondisi;
    }

    // buat setter multiplier ball
    public function setMultiplier_Ball(float $multiplier): void {
        $this->multiplier_Ball = $multiplier;
    }

    public function setMultiplierBall(float $multiplier): void {
        $this->multiplier_Ball = $multiplier;
    }

    // buat setter pasti dapet ball
    public function setPastiDapet_Ball(int $pastiDapet): void {
        $this->pastiDapet_Ball = $pastiDapet;
    }

    public function setPastiDapetBall(int $pastiDapet): void {
        $this->pastiDapet_Ball = $pastiDapet;
    }

    // buat getter kondisi ball
    public function getKondisi_Ball(): string {
        return $this->kondisi_Ball;
    }

    public function getKondisiBall(): string {
        return $this->kondisi_Ball;
    }

    // buat getter multiplier ball
    public function getMultiplier_Ball(): float {
        return $this->multiplier_Ball;
    }

    public function getMultiplierBall(): float {
        return $this->multiplier_Ball;
    }

    // buat getter pasti dapet ball
    public function getPastiDapet_Ball(): int {
        return $this->pastiDapet_Ball;
    }

    public function getPastiDapetBall(): int {
        return $this->pastiDapet_Ball;
    }

    // buat cek status pasti dapat
    public function getKeteranganPastiDapet(): string {
        if ($this->pastiDapet_Ball === 1) {
            return "Pasti dapat Pokemon";
        } else {
            return "Tidak pasti dapat Pokemon";
        }
    }

    // buat cek pasti dapat
    public function cekPastiDapat(): bool {
        return $this->pastiDapet_Ball === 1;
    }

    // buat show data ball
    public function showDataBall(): void {
        echo "Kondisi Ball       : " . $this->kondisi_Ball . "<br>";
        echo "Multiplier Ball    : " . number_format($this->multiplier_Ball, 2) . "x<br>";
        $pastiStr = ($this->pastiDapet_Ball === 1) ? "1 (Pasti dapat Pokemon)" : "0 (Tidak pasti dapat Pokemon)";
        echo "Pasti Dapet        : " . $pastiStr . "<br>";
    }

    // buat show data lengkap
    public function showData(): void {
        echo "----------------------------------------<br>";
        echo "           DATA POKEBALL ITEM           <br>";
        echo "----------------------------------------<br>";
        parent::showData();
        $this->showDataCaptureDevice();
        $this->showDataBall();
        echo "----------------------------------------<br>";
    }
}
?>
