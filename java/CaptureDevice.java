// buat kelas capture device
public class CaptureDevice extends Item {
    private String levelCap_CaptureDevice; // buat level cap device
    private String type_CaptureDevice;     // buat tipe device
    private int isUsable_CaptureDevice;    // buat status usable device (1: true, 0: false)

    // constructor default
    public CaptureDevice() {
        super();
        this.levelCap_CaptureDevice = ""; // kosongin
        this.type_CaptureDevice = "";     // kosongin
        this.isUsable_CaptureDevice = 0;
    }

    // constructor parametrik dengan isUsable
    public CaptureDevice(String id, String nama, double harga, String deskripsi,
                         String levelCap, String type, int isUsable) {
        super(id, nama, harga, deskripsi);
        this.levelCap_CaptureDevice = levelCap;
        this.type_CaptureDevice = type;
        this.isUsable_CaptureDevice = isUsable;
    }

    // constructor parametrik tanpa isUsable (default 0)
    public CaptureDevice(String id, String nama, double harga, String deskripsi,
                         String levelCap, String type) {
        this(id, nama, harga, deskripsi, levelCap, type, 0);
    }

    // buat setter level cap
    public void setLevelCap_CaptureDevice(String levelCap) {
        this.levelCap_CaptureDevice = levelCap;
    }
    public void setLevelCap(String levelCap) {
        this.levelCap_CaptureDevice = levelCap;
    }

    // buat setter type device
    public void setType_CaptureDevice(String type) {
        this.type_CaptureDevice = type;
    }
    public void setType(String type) {
        this.type_CaptureDevice = type;
    }

    // buat setter is usable
    public void setIsUsable_CaptureDevice(int isUsable) {
        this.isUsable_CaptureDevice = isUsable;
    }
    public void setIsUsable(int isUsable) {
        this.isUsable_CaptureDevice = isUsable;
    }

    // buat getter level cap
    public String getLevelCap_CaptureDevice() {
        return this.levelCap_CaptureDevice;
    }
    public String getLevelCap() {
        return this.levelCap_CaptureDevice;
    }

    // buat getter type device
    public String getType_CaptureDevice() {
        return this.type_CaptureDevice;
    }
    public String getType() {
        return this.type_CaptureDevice;
    }

    // buat getter is usable
    public int getIsUsable_CaptureDevice() {
        return this.isUsable_CaptureDevice;
    }
    public int getIsUsable() {
        return this.isUsable_CaptureDevice;
    }

    // buat cek status usable
    public String getKeteranganIsUsable() {
        if (this.isUsable_CaptureDevice == 1) {
            return "Bisa digunakan";
        } else {
            return "Tidak bisa digunakan";
        }
    }

    // buat cek usable (boolean)
    public boolean cekIsUsable() {
        return (this.isUsable_CaptureDevice == 1);
    }

    // buat show data capture device
    public void showDataCaptureDevice() {
        System.out.println("Level Cap Device   : " + this.levelCap_CaptureDevice);
        System.out.println("Type Device        : " + this.type_CaptureDevice);
        System.out.println("Is Usable          : " + (this.isUsable_CaptureDevice == 1 ? "1 (True / Bisa digunakan)" : "0 (False / Tidak bisa digunakan)"));
    }
}
