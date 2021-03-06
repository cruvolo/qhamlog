/*
 * This file is part of QHamLog
 * Copyright (C) 2013 Alex Gladd
 *
 * QHamLog is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QHamLog is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QHamLog.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LOGVIEWER_H
#define LOGVIEWER_H

#include "qsolog.h"
#include <QModelIndex>
#include <QWidget>

namespace Ui {
class LogViewer;
}

class LogViewer : public QWidget
{
    Q_OBJECT

public:
    explicit LogViewer(QWidget *parent = 0);
    ~LogViewer();

public slots:
    void refreshLog();

protected slots:
    void startEdit(const QModelIndex &logTableIndex);

    void stopEdit();

private slots:
    void on_editBtn_clicked();

    void on_cancelBtn_clicked();

    void on_deleteBtn_clicked();

    void on_saveBtn_clicked();

    void on_qsoLogTable_clicked(const QModelIndex &index);

private:
    Ui::LogViewer *ui;

    /* hold a reference to the data model */
    log::QsoLog::Model *logModel;
};

#endif // LOGVIEWER_H
