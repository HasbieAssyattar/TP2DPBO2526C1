#include "Item.cpp"
#include <bits/stdc++.h>

using namespace std;

//buat kelas capture device
class CaptureDevice : public Item {
private:
    string levelCap_CaptureDevice; //buat level cap device
    string type_CaptureDevice;     //buat tipe device
    int isUsable_CaptureDevice;    //buat status usable device (1: true, 0: false)

public:
    //constructor default
    CaptureDevice() : Item() {
        this->levelCap_CaptureDevice = ""; //kosongin
        this->type_CaptureDevice = "";     //kosongin
        this->isUsable_CaptureDevice = 0;
    }

    //constructor parametrik
    CaptureDevice(string id, string nama, double harga, string deskripsi,
                  string levelCap, string type, int isUsable = 0)
        : Item(id, nama, harga, deskripsi) {
        this->levelCap_CaptureDevice = levelCap;
        this->type_CaptureDevice = type;
        this->isUsable_CaptureDevice = isUsable;
    }

    //buat setter level cap
    void setLevelCap_CaptureDevice(const string& levelCap) {
        this->levelCap_CaptureDevice = levelCap;
    }
    void setLevelCap(const string& levelCap) {
        this->levelCap_CaptureDevice = levelCap;
    }

    //buat setter type device
    void setType_CaptureDevice(const string& type) {
        this->type_CaptureDevice = type;
    }
    void setType(const string& type) {
        this->type_CaptureDevice = type;
    }

    //buat setter is usable
    void setIsUsable_CaptureDevice(int isUsable) {
        this->isUsable_CaptureDevice = isUsable;
    }
    void setIsUsable(int isUsable) {
        this->isUsable_CaptureDevice = isUsable;
    }

    //buat getter level cap
    string getLevelCap_CaptureDevice() const {
        return this->levelCap_CaptureDevice;
    }
    string getLevelCap() const {
        return this->levelCap_CaptureDevice;
    }

    //buat getter type device
    string getType_CaptureDevice() const {
        return this->type_CaptureDevice;
    }
    string getType() const {
        return this->type_CaptureDevice;
    }

    //buat getter is usable
    int getIsUsable_CaptureDevice() const {
        return this->isUsable_CaptureDevice;
    }
    int getIsUsable() const {
        return this->isUsable_CaptureDevice;
    }

    //buat cek keterangan status usable
    string getKeteranganIsUsable() const {
        if (this->isUsable_CaptureDevice == 1) {
            return "Bisa digunakan";
        } else {
            return "Tidak bisa digunakan";
        }
    }

    //buat cek usable
    bool cekIsUsable() const {
        return (this->isUsable_CaptureDevice == 1);
    }

    //buat nampilin data capture device
    void showDataCaptureDevice() const {
        cout << "Level Cap Device   : " << this->levelCap_CaptureDevice << endl;
        cout << "Type Device        : " << this->type_CaptureDevice << endl;
        cout << "Is Usable          : " << (this->isUsable_CaptureDevice == 1 ? "1 (True / Bisa digunakan)" : "0 (False / Tidak bisa digunakan)") << endl;
    }

    //destructor
    virtual ~CaptureDevice() {}
};
