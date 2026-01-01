/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../CampusEventClient/client.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN6ClientE_t {};
} // unnamed namespace

template <> constexpr inline auto Client::qt_create_metaobjectdata<qt_meta_tag_ZN6ClientE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Client",
        "connected",
        "",
        "messageReceived",
        "text",
        "jsonReceived",
        "docObj",
        "onReadyRead",
        "sendMessage",
        "type",
        "connectToServer",
        "QHostAddress",
        "address",
        "port",
        "disconnectFromHost"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'connected'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'messageReceived'
        QtMocHelpers::SignalData<void(const QString &)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Signal 'jsonReceived'
        QtMocHelpers::SignalData<void(const QJsonObject &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QJsonObject, 6 },
        }}),
        // Slot 'onReadyRead'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'sendMessage'
        QtMocHelpers::SlotData<void(const QString &, const QString &)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 4 }, { QMetaType::QString, 9 },
        }}),
        // Slot 'sendMessage'
        QtMocHelpers::SlotData<void(const QString &)>(8, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Slot 'connectToServer'
        QtMocHelpers::SlotData<void(const QHostAddress &, quint16)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 11, 12 }, { QMetaType::UShort, 13 },
        }}),
        // Slot 'disconnectFromHost'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Client, qt_meta_tag_ZN6ClientE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Client::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6ClientE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6ClientE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN6ClientE_t>.metaTypes,
    nullptr
} };

void Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Client *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->messageReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->jsonReceived((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 3: _t->onReadyRead(); break;
        case 4: _t->sendMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 5: _t->sendMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->connectToServer((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2]))); break;
        case 7: _t->disconnectFromHost(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Client::*)()>(_a, &Client::connected, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const QString & )>(_a, &Client::messageReceived, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Client::*)(const QJsonObject & )>(_a, &Client::jsonReceived, 2))
            return;
    }
}

const QMetaObject *Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6ClientE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Client::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Client::messageReceived(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void Client::jsonReceived(const QJsonObject & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}
QT_WARNING_POP
