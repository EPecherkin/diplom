#include "exportwidget.h"
#include "ui_exportwidget.h"
#include <QFileDialog>
#include "QDjango.h"
#include "QDjangoQuerySet.h"
#include "macros.h"
#include "desktopservice.h"
#include "exporter.h"

ExportWidget::ExportWidget(User* user, QWidget* parent) : QWidget(parent), ui(new Ui::ExportWidget), _user(user) {
  ui->setupUi(this);
  ui->fromDTE->setDate(QDateTime::currentDateTime().addDays(-1).date());
  ui->toDTE->setDate(QDateTime::currentDateTime().addDays(1).date());
}

ExportWidget::~ExportWidget() {
  delete ui;
}

void ExportWidget::on_exportPB_clicked() {
  FUNCTION

  QDateTime fromDT = ui->fromDTE->dateTime();
  QDateTime toDT = ui->toDTE->dateTime();
  QString format = ui->formatCB->currentText();

  QString filter = QString("%1 (.*%2)").arg(format, format.toLower());
  QString filename = QFileDialog::getSaveFileName(this, "Save file", "", filter);

  QFile file(filename);
  file.open(QIODevice::WriteOnly | QIODevice::Text);
  QTextStream out(&file);

  QList<KeyPress*> keyPressesAll = DesktopService::_instance->server->getKeyPresses(_user);
  QList<KeyPress*> keyPresses;
  for(qint32 i = 0; i < keyPressesAll.size(); ++i) {
    KeyPress* keyPress = keyPressesAll.at(i);
    if((keyPress->start() >= fromDT) && (keyPress->start() <= toDT))
      keyPresses.push_back(keyPress);
  }

  if(format == "CSV") {
    Exporter::exportToCSV(keyPresses, out);
  } else if(format == "JSON") {
    Exporter::exportToJson(keyPresses, out);
  }
}
