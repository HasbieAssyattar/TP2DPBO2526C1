#include <bits/stdc++.h>

using namespace std;

//buat kelas item
class Item {
private:
    string id_Item;        //buat id item
    string nama_Item;      //buat nama item
    double harga_item;     //buat harga item
    string deskripsi_Item; //buat deskripsi item

public:
    //constructor default
    Item() {
        this->id_Item = "";
        this->nama_Item = "";
        this->harga_item = 0.0;
        this->deskripsi_Item = "";
    }

    //constructor parametrik
    Item(string id, string nama, double harga, string deskripsi) {
        this->id_Item = id;
        this->nama_Item = nama;
        this->harga_item = harga;
        this->deskripsi_Item = deskripsi;
    }

    //buat setter id
    void setId(const string& id) {
        this->id_Item = id;
    }

    //buat setter nama
    void setNama(const string& nama) {
        this->nama_Item = nama;
    }

    //buat setter harga
    void setHarga(double harga) {
        this->harga_item = harga;
    }

    //buat setter deskripsi
    void setDeskripsi(const string& deskripsi) {
        this->deskripsi_Item = deskripsi;
    }

    //buat getter id
    string getId() const {
        return this->id_Item;
    }

    //buat getter nama
    string getNama() const {
        return this->nama_Item;
    }

    //buat getter harga
    double getHarga() const {
        return this->harga_item;
    }

    //buat getter deskripsi
    string getDeskripsi() const {
        return this->deskripsi_Item;
    }

    //buat show data
    void showData() const {
        cout << "ID Item        : " << this->id_Item << endl;
        cout << "Nama Item      : " << this->nama_Item << endl;
        cout << "Harga Item     : " << fixed << setprecision(0) << this->harga_item << endl;
        cout << "Deskripsi Item : " << this->deskripsi_Item << endl;
    }

    //destructor
    virtual ~Item() {}
};
