# Copyright (C) 2022 Aleksandr Migunov

# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program. If not, see <https://www.gnu.org/licenses/>.


QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += multimedia

CONFIG += c++11  # Remove or comment this line if Qt5 is old.

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET = CIATE
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

DISTFILES += \
    audios/01a.wav \
    audios/02ae.wav \
    audios/03b.wav \
    audios/04v.wav \
    audios/05g.wav \
    audios/06gh.wav \
    audios/07d.wav \
    audios/08je.wav \
    audios/09jo.wav \
    audios/10zh.wav \
    audios/11z.wav \
    audios/12i.wav \
    audios/13j.wav \
    audios/14k.wav \
    audios/15q.wav \
    audios/16qh.wav \
    audios/17kh.wav \
    audios/18l.wav \
    audios/19m.wav \
    audios/20n.wav \
    audios/21o.wav \
    audios/22oe.wav \
    audios/23p.wav \
    audios/24ph.wav \
    audios/25r.wav \
    audios/26s.wav \
    audios/27t.wav \
    audios/28th.wav \
    audios/29u.wav \
    audios/30ue.wav \
    audios/31f.wav \
    audios/32kh.wav \
    audios/33qh.wav \
    audios/34h.wav \
    audios/35ts.wav \
    audios/36tsh.wav \
    audios/37ch.wav \
    audios/38chh.wav \
    audios/39sh.wav \
    audios/40shh.wav \
    audios/41hard_sign.wav \
    audios/42y.wav \
    audios/43soft_sign.wav \
    audios/44e.wav \
    audios/45ju.wav \
    audios/46jue.wav \
    audios/47ja.wav \
    audios/48jae.wav \
    audios/49ain.wav \
    audios/50b1.wav \
    audios/51v1.wav \
    audios/52d1.wav \
    audios/53zh1.wav \
    audios/54z1.wav \
    audios/55j1.wav \
    audios/56m1.wav \
    audios/57n1.wav \
    audios/alphabet_1.wav \
    audios/alphabet_2.wav \
    audios/alphabet_3.wav \
    audios/alphabet_4.wav \
    audios/alphabet_ingush.wav
