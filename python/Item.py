# buat kelas item
class Item:
    def __init__(self, id_Item: str = "", nama_Item: str = "", harga_item: float = 0.0, deskripsi_Item: str = ""):
        self.__id_Item = str(id_Item)               # buat id item
        self.__nama_Item = str(nama_Item)           # buat nama item
        self.__harga_item = float(harga_item)       # buat harga item
        self.__deskripsi_Item = str(deskripsi_Item) # buat deskripsi item

    # buat setter id
    def setId(self, id_Item):
        self.__id_Item = str(id_Item)

    # buat setter nama
    def setNama(self, nama_Item):
        self.__nama_Item = str(nama_Item)

    # buat setter harga
    def setHarga(self, harga_item):
        self.__harga_item = float(harga_item)

    # buat setter deskripsi
    def setDeskripsi(self, deskripsi_Item):
        self.__deskripsi_Item = str(deskripsi_Item)

    # buat getter id
    def getId(self):
        return self.__id_Item

    # buat getter nama
    def getNama(self):
        return self.__nama_Item

    # buat getter harga
    def getHarga(self):
        return self.__harga_item

    # buat getter deskripsi
    def getDeskripsi(self):
        return self.__deskripsi_Item

    # buat show data
    def showData(self):
        print(f"ID Item        : {self.__id_Item}")
        print(f"Nama Item      : {self.__nama_Item}")
        print(f"Harga Item     : {self.__harga_item:.0f}")
        print(f"Deskripsi Item : {self.__deskripsi_Item}")
