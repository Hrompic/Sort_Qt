TEMPLATE = lib 
CONFIG += c++11
CONFIG += shared
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -llog -landroid
LIBS += -L/system/lib64
QMAKE_LFLAGS += -Wl,--whole-archive /data/data/com.termux/files/usr/lib/libsfml-main.a -Wl,--no-whole-archive
QMAKE_LFLAGS += -Wl, -rpath /data/data/com.termux/files/usr/lib/
SOURCES += \
        main.cpp
