#
# This file is part of QHamLog
# Copyright (C) 2013 Alex Gladd
#
# QHamLog is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# QHamLog is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with QHamLog.  If not, see <http://www.gnu.org/licenses/>.
#
# UI components

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

SOURCES += ui/mainlogwindow.cpp \
    ui/logviewer.cpp \
    ui/qsodataform.cpp \
    ui/aboutdialog.cpp
HEADERS += ui/mainlogwindow.h \
    ui/logviewer.h \
    ui/qsodataform.h \
    ui/aboutdialog.h

FORMS += ui/mainlogwindow.ui \
    ui/logviewer.ui \
    ui/qsodataform.ui \
    ui/aboutdialog.ui
