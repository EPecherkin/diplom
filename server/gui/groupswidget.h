#ifndef GROUPSWIDGET_H
#define GROUPSWIDGET_H

#include <QWidget>

namespace Ui {
class GroupsWidget;
}

class GroupsWidget : public QWidget {
  Q_OBJECT

public:
  explicit GroupsWidget(QWidget* parent = 0);
  ~GroupsWidget();

private slots:
  void on_groupsTW_doubleClicked(const QModelIndex&);
  void on_addPB_clicked();

private:
  Ui::GroupsWidget* ui;

};

#endif // GROUPSWIDGET_H
