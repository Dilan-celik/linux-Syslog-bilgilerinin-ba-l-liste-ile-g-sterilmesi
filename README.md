Sistem Günlükleri (Log) Yönetim Programı
Bu C programı, bir bağlı liste (linked list) veri yapısı kullanarak sistem günlüklerini (loglarını) yönetir. Program, her log kaydını tarih ve saat bilgisiyle birlikte dinamik olarak ekler ve ardından bu logları ekrana yazdırır. Ayrıca, belleği temizler.

Özellikler
Gerçek zamanlı tarih ve saat bilgisini alır.
Her log kaydını bağlı listeye ekler.
Ekranda logları sırasıyla gösterir.
Bellek temizliği yaparak sistem kaynaklarını verimli kullanır.
Gereksinimler
C derleyicisi (gcc veya benzeri)
time.h kütüphanesi
Kod Açıklaması
Bu C programı, bağlı liste veri yapısını kullanarak sistem günlüklerini işler. Programda, her log kaydı oluşturulurken, sistemin o anki tarih ve saati alınır ve her kayda eklenir. Programda üç ana fonksiyon bulunmaktadır: log_ekle, loglari_yazdir ve loglari_temizle.

log_ekle Fonksiyonu
log_ekle fonksiyonu, kullanıcı tarafından sağlanan mesajla birlikte, sistemin o anki tarih ve saat bilgisini alarak bir log kaydı oluşturur. Bu log kaydı, bağlı listeye eklenir. Eğer liste boşsa, yeni kaydı listeye baş olarak ekler, yoksa listeyi dolaşarak sonuna ekler.

Tarih ve saat alımı: Program, time.h kütüphanesini kullanarak mevcut tarih ve saati alır. strftime fonksiyonu ile alınan tarih, istenen formatta (gün, ay, yıl, saat:dakika:saniye) düzenlenir.
Log mesajı ekleme: Mesaj, fonksiyona argüman olarak geçilir ve bağlı listeye eklenir.
loglari_yazdir Fonksiyonu
loglari_yazdir fonksiyonu, bağlı listedeki tüm log kayıtlarını sırasıyla ekrana yazdırır. Bu fonksiyon, listedeki her bir öğeyi ziyaret eder ve her birinin tarih ve mesaj bilgilerini ekrana yazar.

loglari_temizle Fonksiyonu
loglari_temizle fonksiyonu, belleği temizlemek için kullanılır. Bu fonksiyon, bağlı listedeki her öğeyi serbest bırakır ve sistemin belleğini verimli bir şekilde kullanır.
