Proje Hakkında
Bu proje, bir araçta kullanılan çeşitli sensörlerden (sıcaklık, basınç, nem, voltaj vb.) veri toplayarak bu verileri bir ekranda görüntülemeyi amaçlamaktadır. Proje, Arduino platformu üzerinde geliştirilmiştir ve MAX6675 termokupl modülü, DHT22 sıcaklık ve nem sensörü, NTC termistörler ve çeşitli basınç sensörleri kullanılmıştır. Toplanan veriler, araç içindeki bir ekrana veya seri monitöre aktarılabilir.

Kullanılan Sensörler ve Bileşenler
MAX6675: Egzoz gazı sıcaklığını ölçmek için kullanılan termokupl modülü.

DHT22: Ortam sıcaklığı ve nemini ölçen sensör.

NTC Termistörler: Motor sıcaklığı, radyatör giriş/çıkış sıcaklığı vb. ölçümler için kullanılan sensörler.

Basınç Sensörleri: Yağ basıncı, yakıt basıncı ve manifold mutlak basıncı (MAP) ölçümleri için kullanılan sensörler.

Voltaj Bölücü: Araç bataryası voltajını ölçmek için kullanılan devre.

Kullanılan Teknolojiler
Mikrodenetleyici: Arduino (Uno, Nano veya benzeri)

Yazılım: Arduino IDE, C++

Kütüphaneler: MAX6675, DHT

Kurulum
Bu depoyu bilgisayarınıza klonlayın:

bash
Copy
git clone https://github.com/kullanici-adiniz/proje-repo.git  
Arduino IDE'yi açın ve proje.ino dosyasını yükleyin.

Gerekli kütüphaneleri yükleyin:

MAX6675 kütüphanesi

DHT kütüphanesi

Sensörleri ve ekranı devreye bağlayın. Bağlantı şemaları için schematics klasörüne bakın.

Arduino'yu bilgisayarınıza bağlayın ve kodu yükleyin.

Kullanım
Kod yüklendikten sonra, sensörlerden gelen veriler otomatik olarak ekranda görüntülenecektir. Seri monitör üzerinden de verileri gözlemleyebilirsiniz.

Bağlantı Şemaları
Projede kullanılan sensörlerin bağlantı şemaları aşağıdaki gibidir:

MAX6675:

CLK -> Pin 44

CS -> Pin 47

DO -> Pin 46

DHT22:

Data -> Pin 3

NTC Termistörler:

OT -> A1

ECT -> A3

RIT -> A5

ROT -> A7

CHT -> A9

IAT -> A11

T7 -> A13

T8 -> A15

Basınç Sensörleri:

OP -> A0

FP -> A2

MAP -> A4

P4 -> A6

Voltaj Bölücü:

VOLTAGE_PIN -> A8

Katkıda Bulunma
Eğer bu projeye katkıda bulunmak isterseniz, lütfen bir "issue" açın veya bir "pull request" gönderin.

Lisans
Bu proje MIT Lisansı altında lisanslanmıştır. Daha fazla bilgi için LICENSE dosyasına bakın.
