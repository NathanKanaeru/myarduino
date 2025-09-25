//tampilkan tulisan diam-statis-nama masjid dan running text sekolah

  dmd.clearScreen(true);
  
  // Tampilkan "MASJID" di panel kiri atas (posisi x=2)
  Teks = "MASJID";
  pj = Teks.length() + 1;
  char tampil_masjid[pj];
  Teks.toCharArray(tampil_masjid, pj);
  dmd.selectFont(SystemFont5x7);
  dmd.drawString(2, 0, tampil_masjid, pj, 0);
  
  // Tampilkan "AL-HUDA" di panel kanan atas (posisi x=35)  
  Teks = "AL-HUDA";
  pj = Teks.length() + 1;
  char tampil_alhuda[pj];
  Teks.toCharArray(tampil_alhuda, pj);
  dmd.selectFont(SystemFont5x7);
  dmd.drawString(35, 0, tampil_alhuda, pj, 0);
  
  // Setup running text untuk nama sekolah di baris bawah
  Teks = "SMK BHINNEKA KARYA SIMO";
  pj = Teks.length() + 1;
  char tampil_sekolah[pj];
  Teks.toCharArray(tampil_sekolah, pj);
  
  // Inisialisasi marquee di baris bawah (y=9)
  dmd.drawMarquee(tampil_sekolah, pj, 63, 9);
  
  long timer_sekolah = millis();
  boolean ret_sekolah = false;
  
  // Running text sekali saja dengan kecepatan lambat
  while (!ret_sekolah) {
    if ((timer_sekolah + 80) < millis()) {  // kecepatan diperlambat (80ms)
      ret_sekolah = dmd.stepMarquee(-1, 0);
      timer_sekolah = millis();
    }
  }
  
  // Tahan tampilan nama masjid selama 3 detik setelah running text selesai
  delay(3000);
  
  dmd.clearScreen(true);
