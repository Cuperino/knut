/*
  This file is part of Knut.

  SPDX-FileCopyrightText: 2024 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>

  SPDX-License-Identifier: GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

#pragma once

#include <QWidget>

class QLineEdit;

namespace Gui {

class FileSelector : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName NOTIFY fileNameChanged)

public:
    enum class Mode { OpenFile, OpenDirectory, SaveFile };

public:
    explicit FileSelector(QWidget *parent = nullptr);

    QString fileName() const;
    Mode mode() const;

public slots:
    void setFilter(const QString &filter);
    void setFileName(const QString &fileName);
    void setMode(Gui::FileSelector::Mode mode);

signals:
    void fileNameChanged(const QString &fileName);

private:
    void chooseFile();

private:
    QLineEdit *const m_lineEdit;
    QString m_filter;
    Mode m_mode = Mode::OpenFile;
};

} // namespace Gui
