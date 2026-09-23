// buat kelas ball
public class Ball extends CaptureDevice {
    private String kondisi_Ball;    // buat nambah kondisi ball
    private double multiplier_Ball; // buat nambah multiplier ball
    private int pastiDapet_Ball;    // buat nambah pasti dapet ball

    // constructor default
    public Ball() {
        super();
        this.kondisi_Ball = ""; // kosongin
        this.multiplier_Ball = 0.0;
        this.pastiDapet_Ball = 0;
    }

    // constructor parametrik
    public Ball(String id, String namaItem, double harga, String deskripsi,
                String levelCap, String typeDevice,
                String kondisiBall, double multiplierBall, int pastiDapetBall) {
        super(id, namaItem, harga, deskripsi, levelCap, typeDevice);
        this.kondisi_Ball = kondisiBall;
        this.multiplier_Ball = multiplierBall;
        this.pastiDapet_Ball = pastiDapetBall;
    }

    // buat setter kondisi ball
    public void setKondisi_Ball(String kondisiBall) {
        this.kondisi_Ball = kondisiBall;
    }
    public void setKondisiBall(String kondisiBall) {
        this.kondisi_Ball = kondisiBall;
    }

    // buat setter multiplier ball
    public void setMultiplier_Ball(double multiplierBall) {
        this.multiplier_Ball = multiplierBall;
    }
    public void setMultiplierBall(double multiplierBall) {
        this.multiplier_Ball = multiplierBall;
    }

    // buat setter pasti dapet ball
    public void setPastiDapet_Ball(int pastiDapetBall) {
        this.pastiDapet_Ball = pastiDapetBall;
    }
    public void setPastiDapetBall(int pastiDapetBall) {
        this.pastiDapet_Ball = pastiDapetBall;
    }

    // buat getter kondisi ball
    public String getKondisi_Ball() {
        return this.kondisi_Ball;
    }
    public String getKondisiBall() {
        return this.kondisi_Ball;
    }

    // buat getter multiplier ball
    public double getMultiplier_Ball() {
        return this.multiplier_Ball;
    }
    public double getMultiplierBall() {
        return this.multiplier_Ball;
    }

    // buat getter pasti dapet ball
    public int getPastiDapet_Ball() {
        return this.pastiDapet_Ball;
    }
    public int getPastiDapetBall() {
        return this.pastiDapet_Ball;
    }

    // buat cek status pasti dapat
    public String getKeteranganPastiDapet() {
        if (this.pastiDapet_Ball == 1) {
            return "Pasti dapat Pokemon";
        } else {
            return "Tidak pasti dapat Pokemon";
        }
    }

    // buat cek pasti dapat
    public boolean cekPastiDapat() {
        return (this.pastiDapet_Ball == 1);
    }

    // buat show data ball
    public void showDataBall() {
        System.out.println("Kondisi Ball       : " + this.kondisi_Ball);
        System.out.println("Multiplier Ball    : " + String.format(java.util.Locale.US, "%.2fx", this.multiplier_Ball));
        System.out.println("Pasti Dapet        : " + (this.pastiDapet_Ball == 1 ? "1 (Pasti dapat Pokemon)" : "0 (Tidak pasti dapat Pokemon)"));
    }

    // buat show data lengkap
    public void showData() {
        System.out.println("----------------------------------------");
        System.out.println("           DATA POKEBALL ITEM           ");
        System.out.println("----------------------------------------");
        System.out.println("ID Item            : " + getId());
        System.out.println("Nama Item          : " + getNama());
        System.out.println("Harga Item         : " + String.format(java.util.Locale.US, "%.0f", getHarga()));
        System.out.println("Deskripsi Item     : " + getDeskripsi());
        showDataCaptureDevice();
        showDataBall();
        System.out.println("----------------------------------------");
    }
}
