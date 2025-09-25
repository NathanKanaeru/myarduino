//tampilkan tulisan diam-statis-nama masjid dan running text sekolah
  
  // Tampilkan nama masjid statis di baris atas
  Teks = "MASJID AL-HUDA";                    //baris atas - nama masjid statis
  pj = Teks.length() + 1;
  char tampil_masjid[pj];
  Teks.toCharArray(tampil_masjid, pj);
  dmd.selectFont(SystemFont5x7);
  dmd.drawString(5, 0, tampil_masjid, pj, 0); //koordinat tampilan nama masjid
  
  // Setup running text untuk nama sekolah di baris bawah
  Teks = "SMK BHINNEKA KARYA SIMO";           //running text nama sekolah
  pj = Teks.length() + 1;
  char tampil_sekolah[pj];
  Teks.toCharArray(tampil_sekolah, pj);
  
  dmd.drawMarquee(tampil_sekolah, pj, 63, 9);  //mulai marquee di baris bawah (y=9)
  
  long timer_sekolah = millis();
  boolean ret_sekolah = false;
  int durasi_tampil = 0;
  
  // Running text selama 8 detik dengan nama masjid tetap statis di atas
  while (durasi_tampil < 8000) {
    if ((timer_sekolah + 30) < millis()) {  //kecepatan running text
      ret_sekolah = dmd.stepMarquee(-1, 0);
      timer_sekolah = millis();
      durasi_tampil += 30;
      
      // Pertahankan nama masjid tetap tampil di atas
      dmd.selectFont(SystemFont5x7);
      dmd.drawString(5, 0, tampil_masjid, strlen(tampil_masjid)+1, 0);
      
      // Reset marquee jika sudah selesai untuk loop kontinyu
      if (ret_sekolah) {
        dmd.drawMarquee(tampil_sekolah, strlen(tampil_sekolah)+1, 63, 9);
        ret_sekolah = false;
      }
    }
  }
  
  dmd.clearScreen(true);
