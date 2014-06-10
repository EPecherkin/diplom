#ifndef EXPORTWIDGET_H
#define EXPORTWIDGET_H

#include <QWidget>
#include "user.h"

namespace Ui {
class ExportWidget;
}

class ExportWidget : public QWidget {
  Q_OBJECT

public:
  explicit ExportWidget(User* user, QWidget* parent = 0);
  ~ExportWidget();

private slots:
  void on_pathToFilePB_clicked();
  void on_exportPB_clicked();

private:
  Ui::ExportWidget* ui;
  User* _user;

};

#endif // EXPORTWIDGET_H
