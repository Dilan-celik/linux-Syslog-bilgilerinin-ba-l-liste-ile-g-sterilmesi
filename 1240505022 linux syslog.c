#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024

// Bagli liste dugum yapisi
typedef struct LogEntry {
    char tarih[32];  // Tarih ve saat
    char mesaj[MAX_LINE_LENGTH]; // Log mesaji
    struct LogEntry *sonraki;
} LogEntry;

// Yeni bir log ekler
void log_ekle(LogEntry **bas, const char *mesaj) {
    LogEntry *yeni_girdi = (LogEntry *)malloc(sizeof(LogEntry));
    if (!yeni_girdi) {
        perror("Bellek tahsis hatasi");
        exit(EXIT_FAILURE);
    }

    // Guncel tarih ve saati al
    time_t raw_time;
    struct tm *time_info;
    char tarih[32];

    time(&raw_time);  // Mevcut zamani al
    time_info = localtime(&raw_time);  // Yerel zamana donustur

    strftime(tarih, sizeof(tarih), "%d %B %Y %H:%M:%S", time_info);  // Tarih formatini ayarla

    strncpy(yeni_girdi->tarih, tarih, sizeof(yeni_girdi->tarih) - 1);
    yeni_girdi->tarih[sizeof(yeni_girdi->tarih) - 1] = '\0';
    strncpy(yeni_girdi->mesaj, mesaj, sizeof(yeni_girdi->mesaj) - 1);
    yeni_girdi->mesaj[sizeof(yeni_girdi->mesaj) - 1] = '\0';

    yeni_girdi->sonraki = NULL;

    if (*bas == NULL) {
        *bas = yeni_girdi;
    } else {
        LogEntry *temp = *bas;
        while (temp->sonraki) {
            temp = temp->sonraki;
        }
        temp->sonraki = yeni_girdi;
    }
}

// Loglari ekrana yazdir
void loglari_yazdir(LogEntry *bas) {
    LogEntry *temp = bas;
    printf("\n===== Sistem Gunlukleri =====\n");
    while (temp) {
        printf("[%s] %s\n", temp->tarih, temp->mesaj);
        temp = temp->sonraki;
    }
}

// Bellek temizleme
void loglari_temizle(LogEntry *bas) {
    LogEntry *temp;
    while (bas) {
        temp = bas;
        bas = bas->sonraki;
        free(temp);
    }
}

int main() {
    LogEntry *log_listesi = NULL;

    // Ornek loglari ekleyelim
    log_ekle(&log_listesi, "Sistem yoneticisi baslatildi.");
    log_ekle(&log_listesi, "Cekirdek surumu 5.15.0-58-generic.");
    log_ekle(&log_listesi, "Zamanlanmis gorev calistirildi (root).");
    log_ekle(&log_listesi, "Uzaktan baglanti kabul edildi: 192.168.1.100.");
    log_ekle(&log_listesi, "Kullanici yoneticisi durduruluyor.");

    // Loglari yazdir
    loglari_yazdir(log_listesi);

    // Belleði temizle
    loglari_temizle(log_listesi);

    return 0;
}

