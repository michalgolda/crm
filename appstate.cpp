#include "appstate.h"
#include <QString>
#include <QVariant>

#include "appstate.h"

AppState& AppState::instance() {
    static AppState instance;
    return instance;
}

void AppState::set(const QString& key, const QVariant& value) {
    state[key] = value;
}

QVariant AppState::get(const QString& key) const {
    return state.value(key, QVariant());
}


