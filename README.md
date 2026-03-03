# Card-Run Game 🎴

Game berbasis teks sederhana terinspirasi dari genre roguelike deck-building seperti Balatro. Dibuat untuk tugas pretest mata kuliah **Design Pattern**.

## Deskripsi

Game ini mendemonstrasikan penggunaan berbagai design pattern dalam arsitektur game:
- **Creational Pattern**: Factory Pattern
- **Structural Pattern**: Decorator-like modifier chain
- **Behavioral Pattern**: Strategy Pattern (konseptual)

### Alur Permainan
```
Start Run → Play Hand → Calculate Score → Shop (beli modifier) → Repeat (3 ronde) → End Run
```

---

## Arsitektur

### Struktur Folder
```
pretest-design-pattern/
├── src/
│   ├── main.cpp              # Entry point
│   ├── RunSession.cpp/h      # Game loop utama
│   ├── ScoringSystem.cpp/h   # Sistem perhitungan skor
│   ├── ShopSystem.cpp/h      # Sistem toko
│   ├── ModifierFactory.cpp/h # Factory untuk membuat modifier
│   └── modifiers/
│       ├── IModifier.h           # Interface modifier
│       ├── FlatBonusModifier.*   # +20 Chips
│       ├── DoubleScoreModifier.* # x2 Mult
│       └── SquareScoreModifier.* # Mult^2
├── analysis/
│   └── analysis.md           # Dokumen analisis design pattern
├── evidence/
│   └── output.txt            # Output program
└── README.md
```

### Kelas Utama

| Kelas | Peran |
|-------|-------|
| `RunSession` | Mengelola game loop, ronde, dan modifier aktif |
| `ScoringSystem` | Menghitung skor berdasarkan kombinasi kartu poker |
| `ShopSystem` | Menampilkan menu dan menangani pembelian modifier |
| `ModifierFactory` | Membuat instance modifier berdasarkan tipe |
| `IModifier` | Interface untuk semua modifier |

---

## Kompilasi

### Prasyarat

**Linux:**
- g++ (GCC) dengan dukungan C++17

**Windows:**
- MinGW-w64 (g++) atau
- Microsoft Visual Studio dengan MSVC

### Kompilasi di Linux

```bash
# Masuk ke folder src
cd src

# Compile semua file
g++ -std=c++17 -o game_run \
    main.cpp \
    RunSession.cpp \
    ScoringSystem.cpp \
    ShopSystem.cpp \
    ModifierFactory.cpp \
    modifiers/FlatBonusModifier.cpp \
    modifiers/DoubleScoreModifier.cpp \
    modifiers/SquareScoreModifier.cpp

# Jalankan game
./game_run
```

**Atau dengan satu baris:**
```bash
cd src && g++ -std=c++17 -o game_run *.cpp modifiers/*.cpp && ./game_run
```

### Kompilasi di Windows (MinGW)

```cmd
REM Masuk ke folder src
cd src

REM Compile semua file
g++ -std=c++17 -o game_run.exe ^
    main.cpp ^
    RunSession.cpp ^
    ScoringSystem.cpp ^
    ShopSystem.cpp ^
    ModifierFactory.cpp ^
    modifiers/FlatBonusModifier.cpp ^
    modifiers/DoubleScoreModifier.cpp ^
    modifiers/SquareScoreModifier.cpp

REM Jalankan game
game_run.exe
```

**Atau dengan PowerShell:**
```powershell
cd src
g++ -std=c++17 -o game_run.exe main.cpp RunSession.cpp ScoringSystem.cpp ShopSystem.cpp ModifierFactory.cpp modifiers/*.cpp
.\game_run.exe
```

### Kompilasi di Windows (Visual Studio)

1. Buka **Developer Command Prompt for VS**
2. Navigasi ke folder `src`
3. Jalankan:

```cmd
cl /EHsc /std:c++17 /Fe:game_run.exe main.cpp RunSession.cpp ScoringSystem.cpp ShopSystem.cpp ModifierFactory.cpp modifiers\FlatBonusModifier.cpp modifiers\DoubleScoreModifier.cpp modifiers\SquareScoreModifier.cpp

game_run.exe
```

---

## Cara Bermain

1. **Jalankan game** - Tekan Enter untuk memulai
2. **Draw cards** - 8 kartu acak akan ditampilkan
3. **Pilih 5 kartu** - Masukkan nomor kartu (1-8) dipisah spasi
4. **Lihat skor** - Sistem menghitung berdasarkan kombinasi poker
5. **Shop** - Beli modifier untuk meningkatkan skor
6. **Ulangi** - Sampai 3 ronde atau game over

### Kombinasi Kartu (Hand Types)

| Hand | Chips | Mult |
|------|-------|------|
| Straight Flush | 250 | 15 |
| Four of a Kind | 200 | 12 |
| Full House | 160 | 10 |
| Flush | 120 | 8 |
| Straight | 100 | 8 |
| Three of a Kind | 80 | 6 |
| Two Pair | 50 | 4 |
| One Pair | 30 | 3 |
| High Card | 10 | 2 |

### Modifier yang Tersedia

| Modifier | Efek |
|----------|------|
| Flat Bonus | +20 Chips |
| Double Score | x2 Multiplier |
| Square Score | Mult × Mult |

**Formula Skor:** `Total = Chips × Mult`

---

## Design Pattern yang Digunakan

### 1. Factory Pattern (Creational) 

**File:** `ModifierFactory.cpp`

```cpp
IModifier* ModifierFactory::CreateModifier(const std::string& type) {
    if (type == "FlatBonus") return new FlatBonusModifier();
    if (type == "DoubleScore") return new DoubleScoreModifier();
    if (type == "SquareScore") return new SquareScoreModifier();
    return nullptr;
}
```

**Manfaat:** Sentralisasi pembuatan objek modifier, memudahkan penambahan modifier baru.

### 2. Decorator Pattern (Structural) 

**File:** `RunSession.cpp` - `CalculateScore()`

Modifier diterapkan secara berurutan, masing-masing "mendekorasi" skor:

```cpp
for (IModifier* mod : activeModifier) {
    mod->Apply(currentChips, currentMult);
}
```

### 3. Strategy Pattern (Behavioral) 

**Konseptual** - `IModifier` bertindak seperti strategy, di mana setiap modifier memiliki algoritma berbeda untuk memodifikasi skor.

---

## Log Modifikasi

### Menambahkan SquareScoreModifier

**File yang dibuat:**
1. `src/modifiers/SquareScoreModifier.h`
2. `src/modifiers/SquareScoreModifier.cpp`

**File yang dimodifikasi:**
1. `src/ModifierFactory.cpp` - Tambah case "SquareScore"
2. `src/ShopSystem.cpp` - Tambah opsi menu

**Langkah:**
1. Buat kelas baru yang implement `IModifier`
2. Override method `GetName()` dan `Apply()`
3. Daftarkan di `ModifierFactory`
4. Tambahkan ke menu shop

---

## 🤖 Pengungkapan Penggunaan AI

Proyek ini dikembangkan dengan bantuan **GitHub Copilot** untuk:
- Membantu penulisan dokumentasi (`README.md`)
- Memberikan saran struktur kode
- Membantu debugging
---
