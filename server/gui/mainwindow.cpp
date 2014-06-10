#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "macros.h"
#include "groupswidget.h"
#include "logswidget.h"
#include "userswidget.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  on_groupsPB_clicked();
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_groupsPB_clicked() {
  FUNCTION
  QBoxLayout* layout = qobject_cast<QBoxLayout*>(ui->centralwidget->layout());
  QLayoutItem* layoutItem = layout->takeAt(1);
  delete layoutItem->widget();
  delete layoutItem;
  GroupsWidget* gw = new GroupsWidget(this);
  layout->addWidget(gw);
}

void MainWindow::on_usersPB_clicked() {
  FUNCTION
  QBoxLayout* layout = qobject_cast<QBoxLayout*>(ui->centralwidget->layout());
  QLayoutItem* layoutItem = layout->takeAt(1);
  delete layoutItem->widget();
  delete layoutItem;
  UsersWidget* uw = new UsersWidget(0, this);
  layout->addWidget(uw);
}

void MainWindow::on_logsPB_clicked() {
  FUNCTION
  QBoxLayout* layout = qobject_cast<QBoxLayout*>(ui->centralwidget->layout());
  QLayoutItem* layoutItem = layout->takeAt(1);
  delete layoutItem->widget();
  delete layoutItem;
  LogsWidget* lw = new LogsWidget(this);
  layout->addWidget(lw);
}
