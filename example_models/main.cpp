#include "mainwindow.h"

#include <QApplication>
#include <QStringListModel>
#include <QItemSelectionModel>

#include <QTreeView>
#include <QTableView>
#include <QListView>

#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget wgt;

    QStringListModel model;
    model.setStringList(QStringList() << "Item 1" << "Item 2" << "Item 3");

    QTreeView *pTreeView = new QTreeView;
    pTreeView->setModel(&model);

    QTableView *pTableView = new QTableView;
    pTableView->setModel(&model);

    QListView *pListView = new QListView;
    pListView->setModel(&model);

    QItemSelectionModel selection(&model);
    pTreeView->setSelectionModel(&selection);
    pTableView->setSelectionModel(&selection);
    pListView->setSelectionModel(&selection);

    QHBoxLayout* phboxlayout = new QHBoxLayout;
    phboxlayout->addWidget(pTreeView);
    phboxlayout->addWidget(pTableView);
    phboxlayout->addWidget(pListView);

    wgt.setLayout(phboxlayout);
    wgt.show();

    return a.exec();
}
