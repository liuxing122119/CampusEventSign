/****************************************************************************
** Meta object code from reading C++ file 'serverworker.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../ActivityServer/serverworker.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN12ServerWorkerE_t {};
} // unnamed namespace

template <> constexpr inline auto ServerWorker::qt_create_metaobjectdata<qt_meta_tag_ZN12ServerWorkerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ServerWorker",
        "logMessage",
        "",
        "msg",
        "jsonReceived",
        "ServerWorker*",
        "sender",
        "docObj",
        "disconnectedFromClient",
        "onReadyRead",
        "sendMessage",
        "text",
        "type",
        "sendJson",
        "json"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'logMessage'
        QtMocHelpers::SignalData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'jsonReceived'
        QtMocHelpers::SignalData<void(ServerWorker *, const QJsonObject &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 6 }, { QMetaType::QJsonObject, 7 },
        }}),
        // Signal 'disconnectedFromClient'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onReadyRead'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'sendMessage'
        QtMocHelpers::SlotData<void(const QString &, const QString &)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 11 }, { QMetaType::QString, 12 },
        }}),
        // Slot 'sendMessage'
        QtMocHelpers::SlotData<void(const QString &)>(10, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 11 },
        }}),
        // Slot 'sendJson'
        QtMocHelpers::SlotData<void(const QJsonObject &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QJsonObject, 14 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ServerWorker, qt_meta_tag_ZN12ServerWorkerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ServerWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ServerWorkerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ServerWorkerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12ServerWorkerE_t>.metaTypes,
    nullptr
} };

void ServerWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ServerWorker *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->logMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->jsonReceived((*reinterpret_cast< std::add_pointer_t<ServerWorker*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 2: _t->disconnectedFromClient(); break;
        case 3: _t->onReadyRead(); break;
        case 4: _t->sendMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 5: _t->sendMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->sendJson((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ServerWorker* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ServerWorker::*)(const QString & )>(_a, &ServerWorker::logMessage, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ServerWorker::*)(ServerWorker * , const QJsonObject & )>(_a, &ServerWorker::jsonReceived, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ServerWorker::*)()>(_a, &ServerWorker::disconnectedFromClient, 2))
            return;
    }
}

const QMetaObject *ServerWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ServerWorkerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ServerWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ServerWorker::logMessage(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void ServerWorker::jsonReceived(ServerWorker * _t1, const QJsonObject & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void ServerWorker::disconnectedFromClient()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
