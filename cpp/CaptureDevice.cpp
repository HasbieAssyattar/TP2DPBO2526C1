#pragma once
#ifndef CAPTUREDEVICE_H
#define CAPTUREDEVICE_H

#include "Item.cpp"
#include <bits/stdc++.h>

using namespace std;

// Kelas CaptureDevice merupakan turunan (inheritance) dari kelas Item
// Struktur: Item -> CaptureDevice
class CaptureDevice : public Item {
private:
    string levelCap_CaptureDevice;
    string type_CaptureDevice;

public:
    // Konstruktor Default
    CaptureDevice() : Item() {
        this->levelCap_CaptureDevice = "";
        this->type_CaptureDevice = "";
    }

    // Konstruktor Berparameter Lengkap (tanpa atribut foto, levelCap bertipe string)
    CaptureDevice(string id, string nama, double harga, string deskripsi,
                  string levelCap, string type)
        : Item(id, nama, harga, deskripsi) {
        this->levelCap_CaptureDevice = levelCap;
        this->type_CaptureDevice = type;
    }

    // Setter untuk levelCap_CaptureDevice (bertipe string)
    void setLevelCap_CaptureDevice(const string& levelCap) {
        this->levelCap_CaptureDevice = levelCap;
    }
    // Alias sesuai diagram class
    void setLevelCap(const string& levelCap) {
        this->levelCap_CaptureDevice = levelCap;
    }

    // Setter untuk type_CaptureDevice
    void setType_CaptureDevice(const string& type) {
        this->type_CaptureDevice = type;
    }
    // Alias sesuai diagram class
    void setType(const string& type) {
        this->type_CaptureDevice = type;
    }

    // Getter untuk levelCap_CaptureDevice (return string)
    string getLevelCap_CaptureDevice() const {
        return this->levelCap_CaptureDevice;
    }
    // Alias sesuai diagram class
    string getLevelCap() const {
        return this->levelCap_CaptureDevice;
    }

    // Getter untuk type_CaptureDevice
    string getType_CaptureDevice() const {
        return this->type_CaptureDevice;
    }
    // Alias sesuai diagram class
    string getType() const {
        return this->type_CaptureDevice;
    }

    // Method untuk menampilkan informasi CaptureDevice
    void showDataCaptureDevice() const {
        cout << "Level Cap Device   : " << this->levelCap_CaptureDevice << endl;
        cout << "Type Device        : " << this->type_CaptureDevice << endl;
    }

    // Destruktor
    virtual ~CaptureDevice() {}
};

#endif
