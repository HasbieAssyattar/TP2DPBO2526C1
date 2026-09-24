#include "CaptureDevice.cpp"
#include <bits/stdc++.h>

using namespace std;

//buat kelas ball
class Ball : public CaptureDevice {
private:
    string kondisi_Ball;    //buat nambah kondisi ball
    double multiplier_Ball; //buat nambah multiplier ball
    int pastiDapet_Ball;    //buat nambah pasti dapet ball

public:
    //constructor default
    Ball() : CaptureDevice() {
        this->kondisi_Ball = ""; //kosongin
        this->multiplier_Ball = 0.0;
        this->pastiDapet_Ball = 0;
    }

    //constructor parametrik dengan isUsable
    Ball(string id, string namaItem, double harga, string deskripsi,
         string levelCap, string typeDevice, int isUsable,
         string kondisiBall, double multiplierBall, int pastiDapetBall)
        : CaptureDevice(id, namaItem, harga, deskripsi, levelCap, typeDevice, isUsable) {
        this->kondisi_Ball = kondisiBall;
        this->multiplier_Ball = multiplierBall;
        this->pastiDapet_Ball = pastiDapetBall;
    }

    //constructor parametrik tanpa isUsable (default 0)
    Ball(string id, string namaItem, double harga, string deskripsi,
         string levelCap, string typeDevice,
         string kondisiBall, double multiplierBall, int pastiDapetBall)
        : CaptureDevice(id, namaItem, harga, deskripsi, levelCap, typeDevice, 0) {
        this->kondisi_Ball = kondisiBall;
        this->multiplier_Ball = multiplierBall;
        this->pastiDapet_Ball = pastiDapetBall;
    }

    //buat setter kondisi ball
    void setKondisi_Ball(const string& kondisiBall) {
        this->kondisi_Ball = kondisiBall;
    }
    void setKondisiBall(const string& kondisiBall) {
        this->kondisi_Ball = kondisiBall;
    }
    void setKondisi_ball(const string& kondisiBall) {
        this->kondisi_Ball = kondisiBall;
    }
    void setConditionBall(const string& kondisiBall) {
        this->kondisi_Ball = kondisiBall;
    }

    //buat setter multiplier ball
    void setMultiplier_Ball(double multiplierBall) {
        this->multiplier_Ball = multiplierBall;
    }
    void setMultiplierBall(double multiplierBall) {
        this->multiplier_Ball = multiplierBall;
    }
    void setMultiplier_ball(double multiplierBall) {
        this->multiplier_Ball = multiplierBall;
    }

    //buat setter pasti dapet ball
    void setPastiDapet_Ball(int pastiDapetBall) {
        this->pastiDapet_Ball = pastiDapetBall;
    }
    void setPastiDapetBall(int pastiDapetBall) {
        this->pastiDapet_Ball = pastiDapetBall;
    }
    void setPastiDapet_ball(int pastiDapetBall) {
        this->pastiDapet_Ball = pastiDapetBall;
    }

    //buat getter kondisi ball
    string getKondisi_Ball() const {
        return this->kondisi_Ball;
    }
    string getKondisiBall() const {
        return this->kondisi_Ball;
    }
    string getKondisi_ball() const {
        return this->kondisi_Ball;
    }
    string getConditionBall() const {
        return this->kondisi_Ball;
    }

    //buat getter multiplier ball
    double getMultiplier_Ball() const {
        return this->multiplier_Ball;
    }
    double getMultiplierBall() const {
        return this->multiplier_Ball;
    }
    double getMultiplier_ball() const {
        return this->multiplier_Ball;
    }

    //buat getter pasti dapet ball
    int getPastiDapet_Ball() const {
        return this->pastiDapet_Ball;
    }
    int getPastiDapetBall() const {
        return this->pastiDapet_Ball;
    }
    int getPastiDapet_ball() const {
        return this->pastiDapet_Ball;
    }

    //buat cek keterangan status pasti dapat
    string getKeteranganPastiDapet() const {
        if (this->pastiDapet_Ball == 1) {
            return "Pasti dapat Pokemon";
        } else {
            return "Tidak pasti dapat Pokemon";
        }
    }

    //buat cek pasti dapat
    bool cekPastiDapat() const {
        return (this->pastiDapet_Ball == 1);
    }

    //buat show data ball
    void showDataBall() const {
        cout << "Kondisi Ball       : " << this->kondisi_Ball << endl;
        cout << "Multiplier Ball    : " << fixed << setprecision(2) << this->multiplier_Ball << "x" << endl;
        cout << "Pasti Dapet        : " << (this->pastiDapet_Ball == 1 ? "1 (Pasti dapat Pokemon)" : "0 (Tidak pasti dapat Pokemon)") << endl;
    }

    //buat show data
    void showData() const {
        cout << "----------------------------------------" << endl;
        cout << "           DATA POKEBALL ITEM           " << endl;
        cout << "----------------------------------------" << endl;
        cout << "ID Item            : " << getId() << endl;
        cout << "Nama Item          : " << getNama() << endl;
        cout << "Harga Item         : " << fixed << setprecision(0) << getHarga() << endl;
        cout << "Deskripsi Item     : " << getDeskripsi() << endl;
        showDataCaptureDevice();
        showDataBall();
        cout << "----------------------------------------" << endl;
    }

    //destructor
    virtual ~Ball() {}
};
