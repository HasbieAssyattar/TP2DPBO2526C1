#pragma once
#ifndef BALL_H
#define BALL_H

#include "CaptureDevice.cpp"
#include <bits/stdc++.h>

using namespace std;

// Kelas Ball merupakan turunan (inheritance) dari kelas CaptureDevice
// Struktur Inheritance: Item -> CaptureDevice -> Ball
class Ball : public CaptureDevice {
private:
    string kondisi_Ball;
    double multiplier_Ball;
    int pastiDapet_Ball; // 1 = pasti dapet pokemon, 0 = tidak pasti dapet pokemon

public:
    // 1. Konstruktor Default
    Ball() : CaptureDevice() {
        this->kondisi_Ball = "";
        this->multiplier_Ball = 0.0;
        this->pastiDapet_Ball = 0;
    }

    // 2. Konstruktor Berparameter Lengkap (tanpa atribut namaBall dan foto)
    Ball(string id, string namaItem, double harga, string deskripsi,
         string levelCap, string typeDevice,
         string kondisiBall, double multiplierBall, int pastiDapetBall)
        : CaptureDevice(id, namaItem, harga, deskripsi, levelCap, typeDevice) {
        this->kondisi_Ball = kondisiBall;
        this->multiplier_Ball = multiplierBall;
        this->pastiDapet_Ball = pastiDapetBall;
    }

    // ================= Setter =================
    // Setter kondisi_Ball
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

    // Setter multiplier_Ball
    void setMultiplier_Ball(double multiplierBall) {
        this->multiplier_Ball = multiplierBall;
    }
    void setMultiplierBall(double multiplierBall) {
        this->multiplier_Ball = multiplierBall;
    }
    void setMultiplier_ball(double multiplierBall) {
        this->multiplier_Ball = multiplierBall;
    }

    // Setter pastiDapet_Ball (1 = pasti dapet, 0 = ga pasti dapet)
    void setPastiDapet_Ball(int pastiDapetBall) {
        this->pastiDapet_Ball = pastiDapetBall;
    }
    void setPastiDapetBall(int pastiDapetBall) {
        this->pastiDapet_Ball = pastiDapetBall;
    }
    void setPastiDapet_ball(int pastiDapetBall) {
        this->pastiDapet_Ball = pastiDapetBall;
    }

    // ================= Getter =================
    // Getter kondisi_Ball
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

    // Getter multiplier_Ball
    double getMultiplier_Ball() const {
        return this->multiplier_Ball;
    }
    double getMultiplierBall() const {
        return this->multiplier_Ball;
    }
    double getMultiplier_ball() const {
        return this->multiplier_Ball;
    }

    // Getter pastiDapet_Ball (int: 1 atau 0)
    int getPastiDapet_Ball() const {
        return this->pastiDapet_Ball;
    }
    int getPastiDapetBall() const {
        return this->pastiDapet_Ball;
    }
    int getPastiDapet_ball() const {
        return this->pastiDapet_Ball;
    }

    // Method mengecek keterangan status pasti dapat:
    string getKeteranganPastiDapet() const {
        if (this->pastiDapet_Ball == 1) {
            return "Pasti dapat Pokemon";
        } else {
            return "Tidak pasti dapat Pokemon";
        }
    }

    // Method pengecekan nilai (return boolean)
    bool cekPastiDapat() const {
        return (this->pastiDapet_Ball == 1);
    }

    // Method untuk menampilkan atribut khusus Ball (tanpa namaBall)
    void showDataBall() const {
        cout << "Kondisi Ball       : " << this->kondisi_Ball << endl;
        cout << "Multiplier Ball    : " << fixed << setprecision(2) << this->multiplier_Ball << "x" << endl;
        cout << "Pasti Dapet        : " << (this->pastiDapet_Ball == 1 ? "1 (Pasti dapat Pokemon)" : "0 (Tidak pasti dapat Pokemon)") << endl;
    }

    // Method menampilkan semua data dari Item, CaptureDevice, hingga Ball
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

    // Destruktor
    virtual ~Ball() {}
};

#endif
