# VS Code / PlatformIO Geçiş Notları

Bu proje Arduino IDE tek dosya yaklaşımından PlatformIO yapısına taşındı.

## Dosya yapısı
- `src/main.cpp`: uygulama akışı (`setup`, `loop`)
- `src/SensorIO.cpp` + `include/SensorIO.h`: analog okuma ve NTC sıcaklık hesapları
- `src/SensorReader.cpp` + `include/SensorReader.h`: sensörlerden tek noktadan veri toplama
- `src/NextionOutput.cpp` + `include/NextionOutput.h`: Nextion serial çıktı fonksiyonları
- `include/SensorConfig.h`: pinler, katsayılar, sabitler
- `platformio.ini`: kart ve kütüphane ayarları

## VS Code ile kullanım
1. VS Code açın
2. PlatformIO IDE extension kurun
3. Proje klasörünü açın
4. Build: `pio run`
5. Upload: `pio run -t upload`
6. Monitor: `pio device monitor`

## Not
Bu ortamda `pio` CLI kurulu değilse terminalden derleme yapılamaz; VS Code içindeki PlatformIO arayüzüyle çalışabilirsiniz.
