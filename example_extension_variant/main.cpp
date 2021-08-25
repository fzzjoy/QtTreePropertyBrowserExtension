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

#include <QApplication>
#include "variantmanager.h"
#include "variantfactory.h"
#include "qttreepropertybrowser.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QtVariantPropertyManager *variantManager = new VariantManager();
    QtVariantProperty *priority = variantManager->addProperty(QVariant::Int, "Priority");

    priority->setToolTip("Task Priority");

    priority->setAttribute("minimum", 1);
    priority->setAttribute("maximum", 5);
    priority->setValue(3);

    QtVariantProperty *reportType = variantManager->addProperty(QtVariantPropertyManager::enumTypeId(), "Report Type");
    QStringList types;
    types << "Bug" << "Suggestion" << "To Do";
    reportType->setAttribute("enumNames", types);
    reportType->setValue(1); // current value will be "Suggestion"

    QtVariantProperty *task1 = variantManager->addProperty(QtVariantPropertyManager::groupTypeId(), "Task 1");

    task1->addSubProperty(priority);
    task1->addSubProperty(reportType);

    QtTreePropertyBrowser *browser = new QtTreePropertyBrowser();

    QtVariantEditorFactory *variantFactory = new VariantFactory();
    browser->setFactoryForManager(variantManager, variantFactory);

    browser->addProperty(task1);
    browser->show();

    QtVariantProperty *example = variantManager->addProperty(VariantManager::filePathTypeId(), "Example");
    example->setValue("main.cpp");
    example->setAttribute("filter", "Source files (*.cpp *.c)");

    task1->addSubProperty(example);

    return app.exec();
}

