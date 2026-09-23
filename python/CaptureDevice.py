from Item import Item

# buat kelas capture device
class CaptureDevice(Item):
    def __init__(self, id_Item: str = "", nama_Item: str = "", harga_item: float = 0.0, deskripsi_Item: str = "",
                 levelCap: str = "", typeDevice: str = ""):
        super().__init__(id_Item, nama_Item, harga_item, deskripsi_Item)
        self.__levelCap_CaptureDevice = str(levelCap)  # buat level cap device
        self.__type_CaptureDevice = str(typeDevice)    # buat tipe device

    # buat setter level cap
    def setLevelCap_CaptureDevice(self, levelCap):
        self.__levelCap_CaptureDevice = str(levelCap)

    def setLevelCap(self, levelCap):
        self.__levelCap_CaptureDevice = str(levelCap)

    # buat setter type device
    def setType_CaptureDevice(self, typeDevice):
        self.__type_CaptureDevice = str(typeDevice)

    def setType(self, typeDevice):
        self.__type_CaptureDevice = str(typeDevice)

    # buat getter level cap
    def getLevelCap_CaptureDevice(self):
        return self.__levelCap_CaptureDevice

    def getLevelCap(self):
        return self.__levelCap_CaptureDevice

    # buat getter type device
    def getType_CaptureDevice(self):
        return self.__type_CaptureDevice

    def getType(self):
        return self.__type_CaptureDevice

    # buat show data capture device
    def showDataCaptureDevice(self):
        print(f"Level Cap Device   : {self.__levelCap_CaptureDevice}")
        print(f"Type Device        : {self.__type_CaptureDevice}")
