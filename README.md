About the Project
This project aims to collect data from various sensors (temperature, pressure, humidity, voltage, etc.) in a vehicle and display this data on a screen. The project is developed on the Arduino platform and uses the MAX6675 thermocouple module, DHT22 temperature and humidity sensor, NTC thermistors, and various pressure sensors. The collected data can be displayed on an in-car screen or serial monitor.

Sensors and Components Used
MAX6675: Thermocouple module for measuring exhaust gas temperature.

DHT22: Sensor for measuring ambient temperature and humidity.

NTC Thermistors: Sensors for measuring engine temperature, radiator inlet/outlet temperature, etc.

Pressure Sensors: Sensors for measuring oil pressure, fuel pressure, and manifold absolute pressure (MAP).

Voltage Divider: Circuit for measuring vehicle battery voltage.

Technologies Used
Microcontroller: Arduino (Uno, Nano, or similar)

Software: Arduino IDE, C++

Libraries: MAX6675, DHT

Installation
Clone this repository to your computer:

bash
Copy
git clone https://github.com/your-username/project-repo.git  
Open Arduino IDE and load the project.ino file.

Install the necessary libraries:

MAX6675 library

DHT library

Connect the sensors and display to the circuit. Refer to the schematics folder for connection diagrams.

Connect your Arduino to your computer and upload the code.

Usage
Once the code is uploaded, data from the sensors will be automatically displayed on the screen. You can also monitor the data via the serial monitor.

Connection Diagrams
The connection diagrams for the sensors used in the project are as follows:

MAX6675:

CLK -> Pin 44

CS -> Pin 47

DO -> Pin 46

DHT22:

Data -> Pin 3

NTC Thermistors:

OT -> A1

ECT -> A3

RIT -> A5

ROT -> A7

CHT -> A9

IAT -> A11

T7 -> A13

T8 -> A15

Pressure Sensors:

OP -> A0

FP -> A2

MAP -> A4

P4 -> A6

Voltage Divider:

VOLTAGE_PIN -> A8

Contributing
If you would like to contribute to this project, please open an issue or submit a pull request.

License
This project is licensed under the MIT License. See the LICENSE file for more details.

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
