from CaptureDevice import CaptureDevice

# buat kelas ball
class Ball(CaptureDevice):
    def __init__(self, id_Item: str = "", nama_Item: str = "", harga_item: float = 0.0, deskripsi_Item: str = "",
                 levelCap: str = "", typeDevice: str = "",
                 kondisiBall: str = "", multiplierBall: float = 0.0, pastiDapetBall: int = 0):
        super().__init__(id_Item, nama_Item, harga_item, deskripsi_Item, levelCap, typeDevice)
        self.__kondisi_Ball = str(kondisiBall)            # buat nambah kondisi ball
        self.__multiplier_Ball = float(multiplierBall)    # buat nambah multiplier ball
        self.__pastiDapet_Ball = int(pastiDapetBall)      # buat nambah pasti dapet ball

    # buat setter kondisi ball
    def setKondisi_Ball(self, kondisiBall):
        self.__kondisi_Ball = str(kondisiBall)

    def setKondisiBall(self, kondisiBall):
        self.__kondisi_Ball = str(kondisiBall)

    # buat setter multiplier ball
    def setMultiplier_Ball(self, multiplierBall):
        self.__multiplier_Ball = float(multiplierBall)

    def setMultiplierBall(self, multiplierBall):
        self.__multiplier_Ball = float(multiplierBall)

    # buat setter pasti dapet ball
    def setPastiDapet_Ball(self, pastiDapetBall):
        self.__pastiDapet_Ball = int(pastiDapetBall)

    def setPastiDapetBall(self, pastiDapetBall):
        self.__pastiDapet_Ball = int(pastiDapetBall)

    # buat getter kondisi ball
    def getKondisi_Ball(self):
        return self.__kondisi_Ball

    def getKondisiBall(self):
        return self.__kondisi_Ball

    # buat getter multiplier ball
    def getMultiplier_Ball(self):
        return self.__multiplier_Ball

    def getMultiplierBall(self):
        return self.__multiplier_Ball

    # buat getter pasti dapet ball
    def getPastiDapet_Ball(self):
        return self.__pastiDapet_Ball

    def getPastiDapetBall(self):
        return self.__pastiDapet_Ball

    # buat cek status pasti dapat
    def getKeteranganPastiDapet(self):
        if self.__pastiDapet_Ball == 1:
            return "Pasti dapat Pokemon"
        else:
            return "Tidak pasti dapat Pokemon"

    # buat cek pasti dapat
    def cekPastiDapat(self):
        return self.__pastiDapet_Ball == 1

    # buat show data ball
    def showDataBall(self):
        print(f"Kondisi Ball       : {self.__kondisi_Ball}")
        print(f"Multiplier Ball    : {self.__multiplier_Ball:.2f}x")
        pasti_str = "1 (Pasti dapat Pokemon)" if self.__pastiDapet_Ball == 1 else "0 (Tidak pasti dapat Pokemon)"
        print(f"Pasti Dapet        : {pasti_str}")

    # buat show data lengkap
    def showData(self):
        print("----------------------------------------")
        print("           DATA POKEBALL ITEM           ")
        print("----------------------------------------")
        super().showData()
        self.showDataCaptureDevice()
        self.showDataBall()
        print("----------------------------------------")
