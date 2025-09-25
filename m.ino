void tampilNamaMasjid() {
  // teks statis di atas (tengah)
  const char topText[] = "MASJID AL-HUDA";

  // running text di bawah (beri spasi di akhir agar ada jeda)
  const char bottomText[] = "SMK BHINNEKA KARYA SIMO   ";

  // buffer aman
  char bufTop[32];
  char bufBot[128];
  strncpy(bufTop, topText, sizeof(bufTop) - 1);
  bufTop[sizeof(bufTop) - 1] = '\0';
  strncpy(bufBot, bottomText, sizeof(bufBot) - 1);
  bufBot[sizeof(bufBot) - 1] = '\0';

  dmd.selectFont(SystemFont5x7);
  dmd.clearScreen(true);

  // hitung posisi X supaya teks atas rata tengah
  int topLen = strlen(bufTop);
  int topWidth = topLen * 6; // lebar karakter SystemFont5x7 ≈ 6 px
  int posX = (64 - topWidth) / 2;
  if (posX < 0) posX = 0;

  // gambar teks statis atas
  dmd.drawString(posX, 0, bufTop, topLen, 0);
  dmd.drawLine(0, 7, 63, 7, 1); // garis pemisah

  // siapkan marquee teks bawah
  int pj = strlen(bufBot) + 1;
  dmd.drawMarquee(bufBot, pj, 64, 9);

  // --- variabel kecepatan lokal ---
  unsigned long scrollDelay = 40UL; // ms per step scroll

  unsigned long timer = millis();
  bool selesai = false;

  // loop marquee — redraw teks statis setiap step
  while (!selesai) {
    if ((millis() - timer) >= scrollDelay) {
      selesai = dmd.stepMarquee(-1, 0);

      // redraw statis supaya tidak tertimpa
      dmd.selectFont(SystemFont5x7);
      dmd.drawString(posX, 0, bufTop, topLen, 0);
      dmd.drawLine(0, 7, 63, 7, 1);

      timer = millis();
    }
    yield(); // biar sistem lain jalan
  }

  delay(1000);
  dmd.clearScreen(true);
}
