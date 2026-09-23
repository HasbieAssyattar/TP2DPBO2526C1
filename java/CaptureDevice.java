// buat kelas capture device
public class CaptureDevice extends Item {
    private String levelCap_CaptureDevice; // buat level cap device
    private String type_CaptureDevice;     // buat tipe device

    // constructor default
    public CaptureDevice() {
        super();
        this.levelCap_CaptureDevice = ""; // kosongin
        this.type_CaptureDevice = "";     // kosongin
    }

    // constructor parametrik
    public CaptureDevice(String id, String nama, double harga, String deskripsi,
                         String levelCap, String type) {
        super(id, nama, harga, deskripsi);
        this.levelCap_CaptureDevice = levelCap;
        this.type_CaptureDevice = type;
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

    // buat show data capture device
    public void showDataCaptureDevice() {
        System.out.println("Level Cap Device   : " + this.levelCap_CaptureDevice);
        System.out.println("Type Device        : " + this.type_CaptureDevice);
    }
}
