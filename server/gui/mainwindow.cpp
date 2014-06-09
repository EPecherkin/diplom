#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "macros.h"
#include "groupswidget.h"
#include "logswidget.h"
#include "userswidget.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_groupsPB_clicked() {
  FUNCTION
  QGridLayout* layout = qobject_cast<QGridLayout*>(ui->centralwidget->layout());
  QLayoutItem* layoutItem = layout->takeAt(3);
  delete layoutItem->widget();
  delete layoutItem;
  GroupsWidget* gw = new GroupsWidget(this);
  layout->addWidget(gw, 1, 0, 1, 3);
}

void MainWindow::on_usersPB_clicked() {
  FUNCTION
  QGridLayout* layout = qobject_cast<QGridLayout*>(ui->centralwidget->layout());
  QLayoutItem* layoutItem = layout->takeAt(3);
  delete layoutItem->widget();
  delete layoutItem;
  UsersWidget* uw = new UsersWidget(0, this);
  layout->addWidget(uw, 1, 0, 1, 3);
}

void MainWindow::on_logsPB_clicked() {
  FUNCTION
  QGridLayout* layout = qobject_cast<QGridLayout*>(ui->centralwidget->layout());
  QLayoutItem* layoutItem = layout->takeAt(3);
  delete layoutItem->widget();
  delete layoutItem;
  LogsWidget* lw = new LogsWidget(this);
  layout->addWidget(lw, 1, 0, 1, 3);
}
