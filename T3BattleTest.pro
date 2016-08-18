TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    character.cpp \
    battletestsystem.cpp \
    Inventory.cpp \
    weapon.cpp \
    armor.cpp \
    accessory.cpp

HEADERS += \
    character.h \
    battletestsystem.h \
    Singleton.h \
    Inventory.h \
    weapon.h \
    armor.h \
    accessory.h
