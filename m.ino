// Tampilan nama masjid + sekolah (running text bawah)
void tampilNamaMasjid() {
  dmd.clearScreen(true);

  // --- Nama Masjid (statis baris atas) ---
  String Teks = "MASJID AL-IKHLAS";
  int pj = Teks.length() + 1;
  char tampil[pj];
  Teks.toCharArray(tampil, pj);

  dmd.selectFont(SystemFont5x7);
  int posX = (64 - (pj * 6)) / 2;   // pusatkan teks
  if (posX < 0) posX = 0;
  dmd.drawString(posX, 0, tampil, pj, 0);

  // --- Garis pemisah ---
  for (int x = 0; x < 64; x++) {
    dmd.drawLine(x, 7, x, 7, 1);
  }

  // --- Nama Sekolah (running text di baris bawah) ---
  String sekolah = "SMK BHINNEKA KARYA SIMO   "; // kasih spasi biar ada jeda
  pj = sekolah.length() + 1;
  char tampil2[pj];
  sekolah.toCharArray(tampil2, pj);

  // Mulai marquee (start dari kanan layar)
  dmd.drawMarquee(tampil2, pj, 64, 9);
  long timer = millis();
  boolean selesai = false;

  // Jalanin marquee sampai selesai 1 kali
  while (!selesai) {
    if ((timer + 40) < millis()) {   // atur kecepatan scroll (40ms → agak halus)
      selesai = dmd.stepMarquee(-1, 0);
      timer = millis();
    }
  }

  // Delay sebentar setelah selesai
  delay(1000);

  // Clear screen
  dmd.clearScreen(true);
}
