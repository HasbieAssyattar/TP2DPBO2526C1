#include "Item.cpp"
#include <bits/stdc++.h>

using namespace std;

//buat kelas capture device
class CaptureDevice : public Item {
private:
    string levelCap_CaptureDevice; //buat level cap device
    string type_CaptureDevice;     //buat tipe device

public:
    //constructor default
    CaptureDevice() : Item() {
        this->levelCap_CaptureDevice = ""; //kosongin
        this->type_CaptureDevice = "";     //kosongin
    }

    //constructor parametrik
    CaptureDevice(string id, string nama, double harga, string deskripsi,
                  string levelCap, string type)
        : Item(id, nama, harga, deskripsi) {
        this->levelCap_CaptureDevice = levelCap;
        this->type_CaptureDevice = type;
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

    //buat nampilin data capture device
    void showDataCaptureDevice() const {
        cout << "Level Cap Device   : " << this->levelCap_CaptureDevice << endl;
        cout << "Type Device        : " << this->type_CaptureDevice << endl;
    }

    //destructor
    virtual ~CaptureDevice() {}
};
