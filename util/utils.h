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

#ifndef UTILS_H
#define UTILS_H

#include "adifenums.h"
#include <QAbstractItemModel>

namespace utils
{

/**
 * @brief Attempt to retrieve the requested Primary Key data role from the given data model based on
 *   the index that was selected in the model (e.g., from a UI component which is backed by the
 *   given data model)
 * @param pk the resulting Primary Key value
 * @param selectedIndex the index selected in the model view
 * @param model the data model from which to retrieve the primary key
 * @param role the role to use for primary key retrieval (default: adif::enums::Enum::DATA_ROLE_PK)
 * @return true if retrieval of the requested primary key data role from the model is successful for
 *   the given index
 */
extern bool getModelSelectedPk(int *pk, int selectedIndex, const QAbstractItemModel *model, int role = adif::enums::Enum::DATA_ROLE_PK);

} // namespace utils

#endif // UTILS_H