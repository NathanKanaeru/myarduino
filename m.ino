// Panggil ini dari loop() atau saat ingin menampilkan nama masjid + running text
void tampilNamaMasjid() {
  // teks statis di atas (tengah)
  const char topText[] = "MASJID AL-HUDA";

  // running text di bawah (beri spasi di akhir agar ada jeda)
  const char bottomText[] = "SMK BHINNEKA KARYA SIMO   ";

  // buffer aman (maks panjang disesuaikan)
  char bufTop[32];
  char bufBot[128];

  // salin aman ke buffer
  strncpy(bufTop, topText, sizeof(bufTop) - 1);
  bufTop[sizeof(bufTop) - 1] = '\0';
  strncpy(bufBot, bottomText, sizeof(bufBot) - 1);
  bufBot[sizeof(bufBot) - 1] = '\0';

  // pilih font untuk tulisan
  dmd.selectFont(SystemFont5x7);

  // clear layar sekali sebelum start
  dmd.clearScreen(true);

  // hitung posisi X supaya teks atas rata tengah (asumsi lebar char ~6 px: 5+1 spacing)
  int topLen = strlen(bufTop);
  int topWidth = topLen * 6;
  int posX = (64 - topWidth) / 2;
  if (posX < 0) posX = 0;

  // gambar teks atas & garis pemisah sekali (akan digambar ulang tiap step)
  dmd.drawString(posX, 0, bufTop, topLen, 0);
  dmd.drawLine(0, 7, 63, 7, 1); // garis horizontal pemisah

  // siapkan marquee untuk baris bawah (mulai dari kolom 64 sehingga muncul dari kanan)
  int pj = strlen(bufBot) + 1;
  dmd.drawMarquee(bufBot, pj, 64, 9); // y=9 agar berada di baris bawah (untuk 16px tinggi)

  unsigned long timer = millis();
  bool selesai = false;

  // loop marquee — tiap kali step, kita *gambar ulang* teks statis di atas
  while (!selesai) {
    if ((millis() - timer) >= kecepatan) {  // gunakan variabel 'kecepatan' yang sudah ada di sketch
      selesai = dmd.stepMarquee(-1, 0);

      // sangat penting: gambar ulang elemen statis agar tidak tertimpa marquee
      dmd.selectFont(SystemFont5x7);
      dmd.drawString(posX, 0, bufTop, topLen, 0);
      dmd.drawLine(0, 7, 63, 7, 1);

      timer = millis();
    }
    // biarkan sistem lain (interrupt) jalan
    yield();
  }

  // jeda kecil setelah selesai 1 kali scroll
  delay(1000);

  // bersihkan layar kalau perlu
  dmd.clearScreen(true);
}
