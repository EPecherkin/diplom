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
  GroupsWidget* gw = new GroupsWidget;
  gw->show();
}

void MainWindow::on_usersPB_clicked() {
  FUNCTION
  UsersWidget* uw = new UsersWidget;
  uw->show();
}

void MainWindow::on_logsPB_clicked() {
  FUNCTION
  LogsWidget* lw = new LogsWidget;
  lw->show();
}
