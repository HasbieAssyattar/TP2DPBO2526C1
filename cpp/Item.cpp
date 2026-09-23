#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <bits/stdc++.h>

using namespace std;

// Kelas Item sebagai Base Class (Layer 1)
class Item {
private:
    string id_Item;
    string nama_Item;
    double harga_item;
    string deskripsi_Item;

public:
    // Konstruktor Default
    Item() {
        this->id_Item = "";
        this->nama_Item = "";
        this->harga_item = 0.0;
        this->deskripsi_Item = "";
    }

    // Konstruktor Berparameter Lengkap (tanpa atribut foto)
    Item(string id, string nama, double harga, string deskripsi) {
        this->id_Item = id;
        this->nama_Item = nama;
        this->harga_item = harga;
        this->deskripsi_Item = deskripsi;
    }

    // ================= Setter =================
    void setId(const string& id) {
        this->id_Item = id;
    }
    void setNama(const string& nama) {
        this->nama_Item = nama;
    }
    void setHarga(double harga) {
        this->harga_item = harga;
    }
    void setDeskripsi(const string& deskripsi) {
        this->deskripsi_Item = deskripsi;
    }

    // ================= Getter =================
    string getId() const {
        return this->id_Item;
    }
    string getNama() const {
        return this->nama_Item;
    }
    double getHarga() const {
        return this->harga_item;
    }
    string getDeskripsi() const {
        return this->deskripsi_Item;
    }

    // Method menampilkan data Item
    void showData() const {
        cout << "ID Item        : " << this->id_Item << endl;
        cout << "Nama Item      : " << this->nama_Item << endl;
        cout << "Harga Item     : " << fixed << setprecision(0) << this->harga_item << endl;
        cout << "Deskripsi Item : " << this->deskripsi_Item << endl;
    }

    // Destruktor
    virtual ~Item() {}
};

#endif
