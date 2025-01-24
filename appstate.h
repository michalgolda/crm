#ifndef APPSTATE_H
#define APPSTATE_H

#include <QString>
#include <QMap>
#include <QVariant>

class AppState
{
public:
    static AppState& instance(); // Singleton

    void set(const QString& key, const QVariant& value);
    QVariant get(const QString& key) const;

private:
    AppState() = default; // Prywatny konstruktor
    ~AppState() = default; // Prywatny destruktor

    AppState(const AppState&) = delete;            // Usunięcie kopiowania
    AppState& operator=(const AppState&) = delete; // Usunięcie przypisania

    QMap<QString, QVariant> state;
};

#endif // APPSTATE_H
