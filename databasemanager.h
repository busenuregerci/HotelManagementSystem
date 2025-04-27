#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include<QSqlDatabase>

// Bu sınıf veritabanı bağlantısını yönetir
// Singleton olarak tasarlandı: program boyunca 1 tane veritabanı bağlantısı olsun diye.

class DatabaseManager
{
public:
    //DatabaseManager nesnesine erişmek için
    static DatabaseManager* instance();

    // Veritabanı nesnesi almak için
    QSqlDatabase& getDatabase();
private:
    DatabaseManager(); // constructor (veritabanını açıyor)
    ~DatabaseManager(); // deconstructor (program kapanınca veri tabanı kapatılıyor)
    void openDatabase(); // veri tabanı açma işlemini bu mettota yapacağız

    QSqlDatabase m_database; // QT'nin veri tabanı nesnesi
};

#endif // DATABASEMANAGER_H
