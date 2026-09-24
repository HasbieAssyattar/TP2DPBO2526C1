<?php
require_once 'Ball.php';
session_start();

// daftar gambar pokeball yang ada di folder img
$daftarGambar = [];
$imgDir = __DIR__ . '/img';
if (is_dir($imgDir)) {
    $files = scandir($imgDir);
    foreach ($files as $f) {
        if ($f !== '.' && $f !== '..' && preg_match('/\.(jpg|jpeg|png|webp|gif)$/i', $f)) {
            $namaLabel = pathinfo($f, PATHINFO_FILENAME);
            $namaLabel = preg_replace('/(?<!^)(?=[A-Z])/', ' ', $namaLabel);
            $daftarGambar["img/" . $f] = $namaLabel;
        }
    }
}
// fallback jika folder img kosong
if (empty($daftarGambar)) {
    $daftarGambar = [
        "img/PokeBall.jpg" => "Poke Ball",
        "img/DuskBall.jpg" => "Dusk Ball",
        "img/UltraBall.jpg" => "Ultra Ball",
        "img/UltraBeastBall.jpg" => "Beast Ball",
        "img/MasterBall.jpg" => "Master Ball"
    ];
}

// helper cari path foto pokeball (nama pokeball tanpa spasi + .jpg)
function getFotoPokeball($nama, $gambarInput = '') {
    $namaClean = str_replace(' ', '', $nama);
    $imgDir = __DIR__ . '/img';
    if (is_dir($imgDir)) {
        $files = scandir($imgDir);
        foreach ($files as $f) {
            $base = pathinfo($f, PATHINFO_FILENAME);
            if (strcasecmp($base, $namaClean) === 0) {
                return "img/" . $f;
            }
        }
    }
    if (!empty($gambarInput) && file_exists(__DIR__ . '/' . $gambarInput)) {
        return $gambarInput;
    }
    return "img/PokeBall.jpg";
}

// inisialisasi 5 data pokeball awal sesuai inputan fix
if (!isset($_SESSION['daftarItem']) || count($_SESSION['daftarItem']) !== 5 || $_SESSION['daftarItem'][0]->getId() !== 'I01' || !method_exists($_SESSION['daftarItem'][0], 'getIsUsable')) {
    $_SESSION['daftarItem'] = [
        new Ball("I01", "Pokeball", 100.0, "Hanya Pokeball Biasa Dengan Capture Rate 1.0x", "img/PokeBall.jpg", "-", "Pokeball", 0, "-", 1.0, 0),
        new Ball("T02", "Dusk Ball", 150.0, "Hanya Pokeball Dengan Capture Rate 1.0x dan 2.0x Saat Malam", "img/DuskBall.jpg", "20", "Pokeball", 0, "Saat Malam 2.0x", 2.0, 0),
        new Ball("T03", "Ultra Ball", 450.0, "Pokeball Dengan Capture Rate 3.0x", "img/UltraBall.jpg", "15", "Pokeball", 0, "-", 3.0, 0),
        new Ball("T04", "Beast Ball", 700.0, "Pokeball Dengan Capture Rate 1.0x dan 5.0x Saat Ingin Menangkap Ultra Beast Pokemon", "img/BeastBall.jpg", "-", "Pokeball", 0, "Ultra Beast Pokemon 5.0x", 5.0, 0),
        new Ball("T05", "Master Ball", 100000.0, "Pokeball Dengan Capure Rate 100%", "img/MasterBall.jpg", "-", "Pokeball", 0, "-", 1.0, 1)
    ];
}

$daftarItem = &$_SESSION['daftarItem'];
$pesan = "";
$tipePesan = "sukses";
$menu = $_GET['menu'] ?? 'tampil';

// buat cek id
function cekId($id, $daftar) {
    foreach ($daftar as $item) {
        if ($item->getId() === $id) return true;
    }
    return false;
}

// buat tambah item
function tambahItem(&$daftar, $id, $nama, $harga, $deskripsi, $gambar, $levelCap, $type, $isUsable, $kondisi, $multiplier, $pastiDapet) {
    if (cekId($id, $daftar)) return false;
    $gambar = getFotoPokeball($nama, $gambar);
    $daftar[] = new Ball($id, $nama, $harga, $deskripsi, $gambar, $levelCap, $type, $isUsable, $kondisi, $multiplier, $pastiDapet);
    return true;
}

// buat update item
function updateItem(&$daftar, $id, $nama, $harga, $deskripsi, $gambar, $levelCap, $type, $isUsable, $kondisi, $multiplier, $pastiDapet) {
    foreach ($daftar as $item) {
        if ($item->getId() === $id) {
            $item->setNama($nama);
            $item->setHarga($harga);
            $item->setDeskripsi($deskripsi);
            $item->setGambar(getFotoPokeball($nama, $gambar));
            $item->setLevelCap($levelCap);
            $item->setType($type);
            $item->setIsUsable($isUsable);
            $item->setKondisi_Ball($kondisi);
            $item->setMultiplier_Ball($multiplier);
            $item->setPastiDapet_Ball($pastiDapet);
            return true;
        }
    }
    return false;
}

// buat hapus item
function hapusItem(&$daftar, $id) {
    foreach ($daftar as $key => $item) {
        if ($item->getId() === $id) {
            unset($daftar[$key]);
            $daftar = array_values($daftar);
            return true;
        }
    }
    return false;
}

// buat cari item
function cariItem($daftar, $keyword) {
    $hasil = [];
    $keyword = strtolower(trim($keyword));
    foreach ($daftar as $item) {
        if (str_contains(strtolower($item->getId()), $keyword) ||
            str_contains(strtolower($item->getNama()), $keyword) ||
            str_contains(strtolower($item->getType()), $keyword) ||
            str_contains(strtolower($item->getLevelCap()), $keyword) ||
            str_contains(strtolower($item->getKondisi_Ball()), $keyword)) {
            $hasil[] = $item;
        }
    }
    return $hasil;
}

// buat tampil semua
function tampilSemua($daftar) {
    return $daftar;
}

// buat fungsi baru cetak tabel dinamis
function cetakTabel($daftar) {
    if (empty($daftar)) {
        echo '<table><tr><td colspan="12" style="padding: 20px; color: #dc2626;">Data tidak ditemukan / masih kosong bro...</td></tr></table>';
        return;
    }

    echo '<table>';
    echo '<tr>
            <th>No</th>
            <th>Foto Pokeball</th>
            <th>ID Item</th>
            <th>Nama Item</th>
            <th>Harga (Coin)</th>
            <th>Deskripsi Item</th>
            <th>Level Cap Device</th>
            <th>Tipe Device</th>
            <th>Bisa Dipakai Berkali-kali?</th>
            <th>Kondisi Ball</th>
            <th>Multiplier</th>
            <th>Pasti Dapat?</th>
          </tr>';

    $no = 1;
    foreach ($daftar as $b) {
        $usableBadge = ($b->getIsUsable() === 1) 
            ? '<span class="badge badge-success">Ya (Bisa Berkali-kali)</span>' 
            : '<span class="badge badge-secondary">Tidak (Sekali Pakai)</span>';

        $pastiBadge = ($b->getPastiDapet_Ball() === 1) 
            ? '<span class="badge badge-success">Pasti (1)</span>' 
            : '<span style="color: #64748b;">Tidak (0)</span>';
        
        $lvlCapBadge = htmlspecialchars($b->getLevelCap());
        if ($lvlCapBadge !== '-') {
            $lvlCapBadge = '<span class="badge badge-info">' . $lvlCapBadge . '</span>';
        }

        $fotoSrc = getFotoPokeball($b->getNama(), $b->getGambar());
        echo '<tr>
            <td>' . $no++ . '</td>
            <td><img class="ball-img" src="' . htmlspecialchars($fotoSrc) . '" alt="' . htmlspecialchars($b->getNama()) . '" onerror="this.src=\'img/PokeBall.jpg\'"></td>
            <td><strong>' . htmlspecialchars($b->getId()) . '</strong></td>
            <td>' . htmlspecialchars($b->getNama()) . '</td>
            <td>' . number_format($b->getHarga(), 0, ',', '.') . ' Coin</td>
            <td style="text-align: left;">' . htmlspecialchars($b->getDeskripsi()) . '</td>
            <td>' . $lvlCapBadge . '</td>
            <td>' . htmlspecialchars($b->getType()) . '</td>
            <td>' . $usableBadge . '</td>
            <td>' . htmlspecialchars($b->getKondisi_Ball()) . '</td>
            <td>' . number_format($b->getMultiplier_Ball(), 2) . 'x</td>
            <td>' . $pastiBadge . '</td>
        </tr>';
    }
    echo '</table>';
}

// reset data jika diminta
if ($menu === 'reset') {
    unset($_SESSION['daftarItem']);
    header("Location: Main.php?menu=tampil");
    exit;
}

// proses aksi form POST
if (($_SERVER['REQUEST_METHOD'] ?? '') === 'POST') {
    $aksi = $_POST['aksi'] ?? '';

    if ($aksi === 'tambah') {
        $id = trim($_POST['id']);
        $nama = trim($_POST['nama']);
        $harga = floatval($_POST['harga']);
        $deskripsi = trim($_POST['deskripsi']);
        $gambar = trim($_POST['gambar'] ?? 'img/PokeBall.jpg');
        $levelCap = trim($_POST['levelCap']);
        $type = trim($_POST['type']);
        $isUsable = intval($_POST['isUsable'] ?? 0);
        $kondisi = trim($_POST['kondisi']);
        $multiplier = floatval($_POST['multiplier']);
        $pastiDapet = intval($_POST['pastiDapet']);

        if (cekId($id, $daftarItem)) {
            $pesan = "ID Item sudah ada ey, ganti!";
            $tipePesan = "error";
        } elseif ($harga <= 0) {
            $pesan = "itu harga apa utang kok mines";
            $tipePesan = "error";
        } elseif ($multiplier <= 0) {
            $pesan = "Multiplier harus lebih dari 0!";
            $tipePesan = "error";
        } else {
            tambahItem($daftarItem, $id, $nama, $harga, $deskripsi, $gambar, $levelCap, $type, $isUsable, $kondisi, $multiplier, $pastiDapet);
            $pesan = "Pokeball berhasil ditambahkan!";
            $menu = 'tampil';
        }
    } 
    elseif ($aksi === 'update') {
        $id = trim($_POST['id']);
        $nama = trim($_POST['nama']);
        $harga = floatval($_POST['harga']);
        $deskripsi = trim($_POST['deskripsi']);
        $gambar = trim($_POST['gambar'] ?? '');
        $levelCap = trim($_POST['levelCap']);
        $type = trim($_POST['type']);
        $isUsable = intval($_POST['isUsable'] ?? 0);
        $kondisi = trim($_POST['kondisi']);
        $multiplier = floatval($_POST['multiplier']);
        $pastiDapet = intval($_POST['pastiDapet']);

        if (!cekId($id, $daftarItem)) {
            $pesan = "ID gaada loh... pastiin ulang";
            $tipePesan = "error";
        } elseif ($harga <= 0) {
            $pesan = "itu harga apa utang kok mines";
            $tipePesan = "error";
        } elseif ($multiplier <= 0) {
            $pesan = "Multiplier harus lebih dari 0!";
            $tipePesan = "error";
        } else {
            updateItem($daftarItem, $id, $nama, $harga, $deskripsi, $gambar, $levelCap, $type, $isUsable, $kondisi, $multiplier, $pastiDapet);
            $pesan = "Data Pokeball berhasil diupdate!";
            $menu = 'tampil';
        }
    } 
    elseif ($aksi === 'hapus') {
        $id = trim($_POST['id']);
        if (hapusItem($daftarItem, $id)) {
            $pesan = "Data berhasil dihapus!";
            $menu = 'tampil';
        } else {
            $pesan = "Data tidak ditemukan!";
            $tipePesan = "error";
        }
    } 
    elseif ($aksi === 'cek') {
        $id = trim($_POST['id']);
        if (cekId($id, $daftarItem)) {
            $pesan = "ID '$id' SUDAH ADA di dalam daftar!";
            $tipePesan = "error";
        } else {
            $pesan = "ID '$id' BELUM ADA (Tersedia)!";
            $tipePesan = "sukses";
        }
    }
}
?>
<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <title>Sistem PokeCenter - TP2 DPBO</title>
    <style>
        body { font-family: Arial, sans-serif; text-align: center; background-color: #f0f4f8; color: #222; margin: 20px; }
        h1 { color: #dc2626; margin-bottom: 5px; }
        p { color: #555; }
        .menu { margin: 20px 0; }
        .menu a { text-decoration: none; padding: 8px 14px; background-color: #2563eb; color: white; border-radius: 4px; margin: 2px; display: inline-block; font-size: 14px; transition: background-color 0.2s; }
        .menu a:hover { background-color: #1d4ed8; }
        .menu a.reset { background-color: #dc2626; }
        .menu a.reset:hover { background-color: #b91c1c; }
        .pesan { margin: 15px auto; padding: 10px; width: 65%; border-radius: 4px; font-weight: bold; }
        .pesan.sukses { background-color: #d1fae5; color: #065f46; border: 1px solid #a7f3d0; }
        .pesan.error { background-color: #fee2e2; color: #991b1b; border: 1px solid #fecaca; }
        table { margin: 20px auto; border-collapse: collapse; width: 94%; background-color: white; box-shadow: 0 2px 6px rgba(0,0,0,0.1); border-radius: 6px; overflow: hidden; }
        th, td { border: 1px solid #cbd5e1; padding: 10px 8px; text-align: center; font-size: 14px; vertical-align: middle; }
        th { background-color: #1e293b; color: white; }
        tr:nth-child(even) { background-color: #f8fafc; }
        .ball-img { width: 55px; height: 55px; object-fit: contain; border-radius: 6px; background-color: #f8fafc; border: 1px solid #cbd5e1; padding: 2px; vertical-align: middle; transition: transform 0.2s ease; }
        .ball-img:hover { transform: scale(1.2); }
        .badge { padding: 4px 8px; border-radius: 12px; font-size: 12px; font-weight: bold; }
        .badge-success { background-color: #dcfce7; color: #15803d; }
        .badge-info { background-color: #e0f2fe; color: #0369a1; }
        .badge-secondary { background-color: #f1f5f9; color: #64748b; border: 1px solid #cbd5e1; }
        form { display: inline-block; background-color: white; padding: 22px; border: 1px solid #cbd5e1; border-radius: 6px; text-align: left; width: 440px; margin-top: 10px; box-shadow: 0 2px 6px rgba(0,0,0,0.08); }
        fieldset { border: 1px solid #e2e8f0; border-radius: 4px; margin-bottom: 12px; padding: 10px 14px; }
        legend { font-weight: bold; font-size: 12px; color: #2563eb; padding: 0 4px; }
        label { font-weight: bold; font-size: 13px; display: block; margin-top: 6px; }
        input, select { width: 100%; padding: 8px; margin: 4px 0 10px; box-sizing: border-box; border: 1px solid #ccc; border-radius: 4px; font-size: 13px; }
        button { width: 100%; padding: 10px; background-color: #16a34a; color: white; border: none; border-radius: 4px; font-weight: bold; font-size: 14px; cursor: pointer; transition: background-color 0.2s; }
        button:hover { background-color: #15803d; }
        .preview-box { text-align: center; margin: 10px 0 12px; padding: 6px; background-color: #f1f5f9; border-radius: 6px; }
    </style>
</head>
<body>

    <h1>PokeCenter Inventory System</h1>
    <p>Tugas Praktikum 2 (DPBO) - Multi-Layer Inheritance Versi PHP</p>
    <p style="font-size: 12px; color: #64748b;">Item (Layer 1) &rarr; CaptureDevice (Layer 2) &rarr; Ball (Layer 3)</p>

    <!-- Menu Navigasi -->
    <div class="menu">
        <a href="Main.php?menu=tampil">1. Tampil Semua</a>
        <a href="Main.php?menu=tambah">2. Tambah Pokeball</a>
        <a href="Main.php?menu=update">3. Update Pokeball</a>
        <a href="Main.php?menu=hapus">4. Hapus Pokeball</a>
        <a href="Main.php?menu=cari">5. Cari Pokeball</a>
        <a href="Main.php?menu=cek">6. Cek ID</a>
        <a href="Main.php?menu=reset" class="reset">Reset Data</a>
    </div>

    <!-- Notifikasi Pesan -->
    <?php if (!empty($pesan)): ?>
        <div class="pesan <?= $tipePesan ?>"><?= htmlspecialchars($pesan) ?></div>
    <?php endif; ?>

    <!-- 1. TAMPIL SEMUA DATA -->
    <?php if ($menu === 'tampil'): ?>
        <h2>Daftar Semua Pokeball Item</h2>
        <?php cetakTabel($daftarItem); ?>

    <!-- 2. TAMBAH DATA POKEBALL -->
    <?php elseif ($menu === 'tambah'): ?>
        <h2>Tambah Data Pokeball</h2>
        <form method="POST">
            <input type="hidden" name="aksi" value="tambah">

            <fieldset>
                <legend>Layer 1: Item & Gambar</legend>
                <label>ID Item:</label>
                <input type="text" name="id" placeholder="contoh: B05" required>
                <label>Nama Item:</label>
                <input type="text" name="nama" placeholder="nama pokeball/item" required>
                <label>Harga Item (Coin):</label>
                <input type="number" name="harga" min="1" placeholder="harga satuan" required>
                <label>Deskripsi Item:</label>
                <input type="text" name="deskripsi" placeholder="deskripsi barang" required>
                
                <label>Pilihan Gambar Pokeball:</label>
                <select name="gambar" onchange="previewImg('previewTambah', this.value)">
                    <?php foreach ($daftarGambar as $path => $label): ?>
                        <option value="<?= $path ?>"><?= $label ?> (<?= basename($path) ?>)</option>
                    <?php endforeach; ?>
                </select>
                <div class="preview-box">
                    <span style="font-size: 11px; color: #64748b; display: block; margin-bottom: 4px;">Preview Gambar:</span>
                    <img id="previewTambah" class="ball-img" src="<?= array_key_first($daftarGambar) ?>" alt="Preview" style="width: 70px; height: 70px;">
                </div>
            </fieldset>

            <fieldset>
                <legend>Layer 2: CaptureDevice</legend>
                <label>Level Cap Device:</label>
                <input type="text" name="levelCap" placeholder="contoh: Level 50 ke atas / Bebas" required>
                <label>Tipe Device:</label>
                <input type="text" name="type" placeholder="Pokeball" required>
                <label>Bisa Dipakai Berkali-kali? (Is Usable):</label>
                <select name="isUsable">
                    <option value="0">0 - Tidak (Sekali Pakai)</option>
                    <option value="1">1 - Ya (Bisa Dipakai Berkali-kali)</option>
                </select>
            </fieldset>

            <fieldset>
                <legend>Layer 3: Ball</legend>
                <label>Kondisi Ball:</label>
                <input type="text" name="kondisi" placeholder="contoh: Saat malam hari / di dalam gua (3x multiplier)" required>
                <label>Catch Multiplier:</label>
                <input type="number" step="0.1" name="multiplier" min="0.1" value="1.0" required>
                <label>Pasti Dapat?:</label>
                <select name="pastiDapet">
                    <option value="0">0 - Tidak Pasti Dapat</option>
                    <option value="1">1 - Pasti Dapat (Master)</option>
                </select>
            </fieldset>

            <button type="submit">Tambah Pokeball</button>
        </form>

    <!-- 3. UPDATE DATA POKEBALL -->
    <?php elseif ($menu === 'update'): ?>
        <h2>Update Data Pokeball</h2>
        <form method="POST">
            <input type="hidden" name="aksi" value="update">
            <label>Pilih ID yang Ingin Diubah:</label>
            <select name="id" required>
                <?php foreach ($daftarItem as $item): ?>
                    <option value="<?= htmlspecialchars($item->getId()) ?>"><?= htmlspecialchars($item->getId()) ?> - <?= htmlspecialchars($item->getNama()) ?></option>
                <?php endforeach; ?>
            </select>

            <fieldset>
                <legend>Layer 1: Item & Gambar Baru</legend>
                <label>Nama Item Baru:</label>
                <input type="text" name="nama" placeholder="nama baru" required>
                <label>Harga Item Baru (Coin):</label>
                <input type="number" name="harga" min="1" placeholder="harga baru" required>
                <label>Deskripsi Baru:</label>
                <input type="text" name="deskripsi" placeholder="deskripsi baru" required>
                
                <label>Pilihan Gambar Pokeball Baru:</label>
                <select name="gambar" onchange="previewImg('previewUpdate', this.value)">
                    <?php foreach ($daftarGambar as $path => $label): ?>
                        <option value="<?= $path ?>"><?= $label ?> (<?= basename($path) ?>)</option>
                    <?php endforeach; ?>
                </select>
                <div class="preview-box">
                    <span style="font-size: 11px; color: #64748b; display: block; margin-bottom: 4px;">Preview Gambar Baru:</span>
                    <img id="previewUpdate" class="ball-img" src="<?= array_key_first($daftarGambar) ?>" alt="Preview" style="width: 70px; height: 70px;">
                </div>
            </fieldset>

            <fieldset>
                <legend>Layer 2: CaptureDevice Baru</legend>
                <label>Level Cap Baru:</label>
                <input type="text" name="levelCap" placeholder="level cap baru" required>
                <label>Tipe Device Baru:</label>
                <input type="text" name="type" placeholder="Pokeball" required>
                <label>Bisa Dipakai Berkali-kali Baru? (Is Usable):</label>
                <select name="isUsable">
                    <option value="0">0 - Tidak (Sekali Pakai)</option>
                    <option value="1">1 - Ya (Bisa Dipakai Berkali-kali)</option>
                </select>
            </fieldset>

            <fieldset>
                <legend>Layer 3: Ball Baru</legend>
                <label>Kondisi Ball Baru:</label>
                <input type="text" name="kondisi" placeholder="contoh: Saat malam hari / di dalam gua (3x multiplier)" required>
                <label>Multiplier Baru:</label>
                <input type="number" step="0.1" name="multiplier" min="0.1" value="1.0" required>
                <label>Pasti Dapat?:</label>
                <select name="pastiDapet">
                    <option value="0">0 - Tidak Pasti Dapat</option>
                    <option value="1">1 - Pasti Dapat</option>
                </select>
            </fieldset>

            <button type="submit" style="background-color: #2563eb;">Update Pokeball</button>
        </form>

    <!-- 4. HAPUS DATA POKEBALL -->
    <?php elseif ($menu === 'hapus'): ?>
        <h2>Hapus Data Pokeball</h2>
        <form method="POST">
            <input type="hidden" name="aksi" value="hapus">
            <label>Pilih ID Pokeball yang Ingin Dihapus:</label>
            <select name="id" required>
                <?php foreach ($daftarItem as $item): ?>
                    <option value="<?= htmlspecialchars($item->getId()) ?>"><?= htmlspecialchars($item->getId()) ?> - <?= htmlspecialchars($item->getNama()) ?></option>
                <?php endforeach; ?>
            </select>
            <button type="submit" style="background-color: #dc2626; margin-top: 15px;">Hapus Data</button>
        </form>

    <!-- 5. CARI DATA POKEBALL -->
    <?php elseif ($menu === 'cari'): ?>
        <h2>Cari Data Pokeball</h2>
        <form method="GET">
            <input type="hidden" name="menu" value="cari">
            <label>Masukkan Kata Kunci (ID / Nama / Tipe Device / Kondisi):</label>
            <input type="text" name="keyword" value="<?= htmlspecialchars($_GET['keyword'] ?? '') ?>" placeholder="contoh: Ultra / Net / Malam" required>
            <button type="submit">Cari Data</button>
        </form>

        <?php if (isset($_GET['keyword'])): ?>
            <?php $hasil = cariItem($daftarItem, $_GET['keyword']); ?>
            <h3 style="margin-top: 30px;">Hasil Pencarian untuk: "<?= htmlspecialchars($_GET['keyword']) ?>"</h3>
            <?php cetakTabel($hasil); ?>
        <?php endif; ?>

    <!-- 6. CEK ID -->
    <?php elseif ($menu === 'cek'): ?>
        <h2>Cek Ketersediaan ID Pokeball</h2>
        <form method="POST">
            <input type="hidden" name="aksi" value="cek">
            <label>Masukkan ID yang Ingin Dicek:</label>
            <input type="text" name="id" placeholder="contoh: B01 / B99" required>
            <button type="submit" style="background-color: #0284c7;">Cek ID</button>
        </form>
    <?php endif; ?>

    <script>
        function previewImg(targetId, src) {
            var el = document.getElementById(targetId);
            if (el) el.src = src;
        }
    </script>
</body>
</html>
