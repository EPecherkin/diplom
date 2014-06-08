#include "exportwidget.h"
#include "ui_exportwidget.h"
#include <QFileDialog>
#include "macros.h"

ExportWidget::ExportWidget(QWidget* parent) : QWidget(parent), ui(new Ui::ExportWidget) {
  ui->setupUi(this);
}

ExportWidget::~ExportWidget() {
  delete ui;
}

void ExportWidget::on_exportPB_clicked() {
  FUNCTION
  QString format = ui->formatCB->currentText();
  QString filter = QString("%1 (.*%2)").arg(format, format.toLower());
  QString filename = QFileDialog::getSaveFileName(this, "Save file", "", filter);
}
