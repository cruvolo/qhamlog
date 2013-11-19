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

#ifndef QSOLOG_H
#define QSOLOG_H

#include "sqlitedbprovider.h"
#include <QSqlQueryModel>
#include <QDateTime>
#include <QVariant>

namespace log
{

// forward decl
class Qso;

/**
 * @brief Wrapper for access to the QSO log database
 */
class QsoLog : public SqliteDbProvider
{
public:
    // forward decl
    class Model;

    /**
     * @brief Destructor
     */
    virtual ~QsoLog();

    /**
     * @brief Initialize the singleton QSO log
     * @param dbPath file system path to the QSO log database file
     * @return true if initialization is successful
     */
    static bool init(const std::string &dbPath);

    /**
     * @brief Dispose of all resources held by the QSO log; use of the QSO log is undefined after
     *   this call
     */
    static void destroy();

    /**
     * @brief Retrieve the qso log data model
     * @return pointer to an initialized qso log data model
     */
    static Model *getModel();

    /**
     * @brief Add the given QSO to the log; assumes the given QSO was validated elsewhere
     * @param qso the QSO to add
     * @return true if the QSO was added to the log successfully
     */
    static bool addQso(const Qso &qso);

    /**
     * @brief Update the given QSO in the log; assumes the given QSO was validated elsewhere
     * @param qso the QSO to update
     * @return true if the QSO was updated successfully
     */
    static bool updateQso(const Qso &qso);

    /**
     * @brief Remove the given QSO from the log
     * @param qso the QSO to remove
     * @return true if the QSO was removed successfully
     */
    static bool removeQso(const Qso &qso);

    /**
     * @brief Defines a data model for the QSO log
     */
    class Model : public QSqlQueryModel
    {
    public:
        /**
         * @brief Constructor
         * @param db the database reference to use
         * @param parent the model's parent (default NULL)
         */
        Model(const QSqlDatabase &db, QObject *parent = NULL);

        /**
         * @brief Destructor
         */
        virtual ~Model();

        /* column names */
        static const QString ID;
        static const QString CALLSIGN;
        static const QString TIME_ON_UTC;
        static const QString TIME_OFF_UTC;
        static const QString BAND;
        static const QString MODE;
        static const QString SUBMODE;
        static const QString FREQ_MHZ;
        static const QString POWER_W;
        static const QString RST_SENT;
        static const QString RST_RECV;
        static const QString CITY;
        static const QString COUNTRY;
        static const QString PRIMARY_SUB;
        static const QString SECONDARY_SUB;
        static const QString COMMENTS;
        static const QString QSO_MSG;

    protected:
        /**
         * @brief Set a friendly header label for the given field name
         * @param fieldName the field name the label will be set for
         * @param label the label to set
         */
        void setHeaderLabel(const QString &fieldName, const QString &label);
    };

protected:
    /**
     * @brief Default constructor (don't need to directly instantiate)
     */
    QsoLog();

    /**
     * @brief Singleton instance of the QSO log
     */
    static QsoLog *instance;

};


/**
 * @brief Simple data structure for a single QSO
 */
class Qso
{
public:
    /**
     * @brief Default constructor
     */
    Qso();

    /**
     * @brief Constructor for setting minimum QSO parameters in one call
     * @param callsign the contacted station's callsign
     * @param timeOnUtc the time the QSO began (UTC)
     * @param band the band the QSO took place on
     * @param mode the mode used for the QSO
     */
    Qso(const QString &callsign, const QDateTime &timeOnUtc, const QString &band, const QString &mode);

    /**
     * @brief Destructor
     */
    virtual ~Qso();

    QString callsign;
    QDateTime timeOnUtc;
    QDateTime timeOffUtc;
    QString band;
    QString mode;
    QString submode;
    QVariant freqMhz;
    QVariant powerWatts;
    QVariant rstSent;
    QVariant rstRecv;
    QString city;
    QString country;
    QString primaryAdminSub;
    QString secondaryAdminSub;
    QString comments;
    QString qsoMsg;

protected:
    QVariant id;

    friend bool QsoLog::updateQso(const Qso &qso);
    friend bool QsoLog::removeQso(const Qso &qso);
};

} // namespace log

#endif // QSOLOG_H