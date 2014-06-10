#include "userswidget.h"
#include "ui_userswidget.h"
#include "QDjango.h"
#include "QDjangoQuerySet.h"
#include "macros.h"
#include "usereditdialog.h"
#include "keypress.h"

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
  UserEditDialog* ued = new UserEditDialog(user, this);
  connect(ued, SIGNAL(finished(int)), this, SLOT(renderData()));
  ued->show();
}

void UsersWidget::on_addPB_clicked() {
  FUNCTION
  User* user = new User;
  Group* group = QDjangoQuerySet<Group>().get(QDjangoWhere("id", QDjangoWhere::Equals, 1));
  user->group(group);
  UserEditDialog* ued = new UserEditDialog(user, this);
  connect(ued, SIGNAL(finished(int)), this, SLOT(renderData()));
  ued->show();
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
    QTableWidgetItem* item1 = new QTableWidgetItem(user->firstName());
    QTableWidgetItem* item2 = new QTableWidgetItem(user->lastName());
    QTableWidgetItem* item3 = new QTableWidgetItem(user->middleName());
    Group* group = QDjangoQuerySet<Group>().get(QDjangoWhere("id", QDjangoWhere::Equals, user->property("group_id")));
    QTableWidgetItem* item4 = new QTableWidgetItem(group->name());
    QTableWidgetItem* item5;
    QDjangoQuerySet<KeyPress> kpqs = QDjangoQuerySet<KeyPress>().filter(QDjangoWhere("user_id", QDjangoWhere::Equals, user->pk())).orderBy(QStringList() << "-start");
    if(kpqs.size() > 0) {
      QDateTime lastActivity = kpqs.at(0)->start();
      item5 = new QTableWidgetItem(lastActivity.toString());
    } else {
      item5 = new QTableWidgetItem("No activity");
    }

    ui->usersTW->setItem(i, 0, item0);
    ui->usersTW->setItem(i, 1, item1);
    ui->usersTW->setItem(i, 2, item2);
    ui->usersTW->setItem(i, 3, item3);
    ui->usersTW->setItem(i, 4, item4);
    ui->usersTW->setItem(i, 5, item5);
  }
}
