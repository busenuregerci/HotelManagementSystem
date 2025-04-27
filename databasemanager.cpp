#include "databasemanager.h"
#include<QDebug>
#include<QSqlError>

using namespace std;

DatabaseManager::DatabaseManager()
{
    openDatabase(); // Nesne oluşturulduğunda veritabanını aç
}

DatabaseManager::~DatabaseManager()
{
    if(m_database.isOpen())
    {
        m_database.close(); // nesne yok edilirken veritabanını da kapat
    }
}

DatabaseManager* DatabaseManager::instance()
{
    // Singleton deseni uyguluyoruz:
    // Program boyunca sadece 1 adet DatabaseManager nesnesi olacak

    static DatabaseManager instance;
    return &instance;
}

void DatabaseManager::openDatabase()
{
    m_database = QSqlDatabase::addDatabase("QODBC"); //MsSql

    QString serverName = "DESKTOP-DPOS3IC\\MSSQLSERVER1";
    QString databaseName = "HotelDB";
    QString userName = "sa";
    QString password ="123";

    QString dsn = QString("Driver={SQL Server}; Server=%1; Database=%2; ")
                      .arg(serverName)
                      .arg(databaseName);

    m_database.setDatabaseName(dsn);
    m_database.setUserName(userName);
    m_database.setPassword(password);

    if(!m_database.open())
    {
        qDebug() << "Database is not open: " <<m_database.lastError().text();
    }
    else
    {
        qDebug() << "Database is open";
    }

}

QSqlDatabase& DatabaseManager::getDatabase()
{
    if (!m_database.isOpen()) {
        m_database.open(); // Eğer kapalıysa aç
    }
    return m_database;
}
