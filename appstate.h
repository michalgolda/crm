#ifndef APPSTATE_H
#define APPSTATE_H

#include <QString>

class AppState {
public:
    static AppState& instance() {
        static AppState instance;
        return instance;
    }

    bool isLoggedIn = false;
    QString username = QString();

    AppState(const AppState&) = delete;
    AppState& operator=(const AppState&) = delete;

private:
    AppState() {}
};

#endif // APPSTATE_H
