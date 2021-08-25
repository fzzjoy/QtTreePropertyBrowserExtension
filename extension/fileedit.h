/****************************************************************************
**
** Copyright (C) 2006 Trolltech ASA. All rights reserved.
**
** This file is part of the documentation of Qt. It was originally
** published as part of Qt Quarterly.
**
** This file may be used under the terms of the GNU General Public License
** version 2.0 as published by the Free Software Foundation or under the
** terms of the Qt Commercial License Agreement. The respective license
** texts for these are provided with the open source and commercial
** editions of Qt.
**
** If you are unsure which license is appropriate for your use, please
** review the following information:
** http://www.trolltech.com/products/qt/licensing.html or contact the
** sales department at sales@trolltech.com.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#ifndef FILEEDIT_H
#define FILEEDIT_H

#include <QLineEdit>

class FileEdit : public QWidget
{
    Q_OBJECT
public:
    enum FileMode
    {
        FileMode_getExistingDirectory = 0,  // 选取路径
        FileMode_getOpenFileName,           // 打开文件
        FileMode_getSaveFileName            // 保存文件
    };

    FileEdit(QWidget *parent = 0);
    void setFilePath(const QString &filePath) { if (theLineEdit->text() != filePath) theLineEdit->setText(filePath); }
    QString filePath() const { return theLineEdit->text(); }
    void setFilter(const QString &filter) { theFilter = filter; }
    QString filter() const { return theFilter; }
    void setFileMode(const int mode)
    {
        if(mode >= FileMode_getExistingDirectory && mode <= FileMode_getSaveFileName)
        {
            theFileMode = static_cast<FileMode>(mode);
        }
        else
        {
            theFileMode = FileMode_getExistingDirectory;
        }
    }
    int fileMode() const {return theFileMode;}

signals:
    void filePathChanged(const QString &filePath);
protected:
    void focusInEvent(QFocusEvent *e);
    void focusOutEvent(QFocusEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
private slots:
    void buttonClicked();
private:
    FileMode theFileMode = FileMode_getExistingDirectory;
    QLineEdit *theLineEdit;
    QString theFilter;
};

#endif
