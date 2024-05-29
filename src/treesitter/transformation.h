/*
  This file is part of Knut.

  SPDX-FileCopyrightText: 2024 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>

  SPDX-License-Identifier: GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

#pragma once

#include "parser.h"
#include "query.h"

#include <QString>

namespace treesitter {

class Transformation
{
public:
    struct Error
    {
        QString description;
    };

    Transformation(QString source, Parser &&parser, std::shared_ptr<Query> query, QString transformationTarget);

    // Throws a Transformation::Error on failure
    QString run();

    int replacementsMade() const { return m_replacements; }

private:
    bool runOneTransformation(QueryCursor &cursor, QString &resultText);

    QString m_source;
    Parser m_parser;
    std::shared_ptr<Query> m_query;
    QString m_to;

    // After reaching max_replacements, stop the transformation.
    // This likely means the transformation is recursive and will never finish.
    int m_max_replacements = 100;
    int m_replacements = 0;
};

}
