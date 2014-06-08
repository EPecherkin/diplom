#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "macros.h"
#include "desktopservice.h"
#include "usereditdialog.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  UserEditDialog* ued = new UserEditDialog(DesktopService::_instance->currentUser);
  setCentralWidget(ued);
}

MainWindow::~MainWindow() {
  delete ui;
}
