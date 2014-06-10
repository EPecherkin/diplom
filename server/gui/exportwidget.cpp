#include "exportwidget.h"
#include "ui_exportwidget.h"
#include <QFileDialog>
#include "macros.h"

ExportWidget::ExportWidget(User* user, QWidget* parent) : QWidget(parent), ui(new Ui::ExportWidget), _user(user) {
  ui->setupUi(this);
  ui->fromDTE->setDate(QDateTime::currentDateTime().addDays(-1).date());
  ui->toDTE->setDate(QDateTime::currentDateTime().addDays(1).date());
}

ExportWidget::~ExportWidget() {
  delete ui;
}

void ExportWidget::on_pathToFilePB_clicked() {
  QString format = ui->formatCB->currentText();
  QString filter = QString("%1 (.*%2)").arg(format, format.toLower());
  QString filename = QFileDialog::getSaveFileName(this, "Save file", "", filter);
  ui->pathToFileLE->setText(filename);
}

void ExportWidget::on_exportPB_clicked() {
  FUNCTION
}
