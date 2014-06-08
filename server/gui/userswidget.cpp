#include "userswidget.h"
#include "ui_userswidget.h"
#include "macros.h"
#include "QDjango.h"
#include "QDjangoQuerySet.h"
#include "usereditdialog.h"

UsersWidget::UsersWidget(Group* group, QWidget* parent) : QWidget(parent), ui(new Ui::UsersWidget), _group(group), _users(QList<User*>()) {
  ui->setupUi(this);

  renderData();
}

UsersWidget::~UsersWidget() {
  delete ui;
}

void UsersWidget::on_usersTW_doubleClicked(const QModelIndex& index) {
  FUNCTION
  User* user = _users.at(index.row());
  UserEditDialog* ued = new UserEditDialog(user);
  ued->exec();
  renderData();
}

void UsersWidget::on_addPB_clicked() {
  FUNCTION
  User* user = new User;
  Group* group = QDjangoQuerySet<Group>().get(QDjangoWhere("id", QDjangoWhere::Equals, 1));
  user->group(group);
  UserEditDialog* ued = new UserEditDialog(user);
  ued->exec();
  renderData();
}

void UsersWidget::renderData() {
  FUNCTION
  QDjangoQuerySet<User> uqs;
  if(_group != 0) {
    uqs = QDjangoQuerySet<User>().filter(QDjangoWhere("group_id", QDjangoWhere::Equals, _group->pk()));
  } else {
    uqs = QDjangoQuerySet<User>().all();
  }

  ui->usersTW->setRowCount(uqs.size());

  for(qint32 i = 0; i < uqs.size(); ++i) {
    User* user = uqs.at(i);
    _users.append(user);

    QTableWidgetItem* item0 = new QTableWidgetItem(user->login());
    QString fullName = QString().append(user->lastName()).append(" ").append(user->firstName()).append(" ").append(user->middleName());
    QTableWidgetItem* item1 = new QTableWidgetItem(fullName);
    QTableWidgetItem* item2 = new QTableWidgetItem(user->group()->name());

    ui->usersTW->setItem(i, 0, item0);
    ui->usersTW->setItem(i, 1, item1);
    ui->usersTW->setItem(i, 2, item2);
  }
}
