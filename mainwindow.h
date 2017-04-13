#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memberlist.h>
#include <itemlist.h>
#include <sstream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void appendMemberToTable(int i);
    void displayMsgBox(std::string message) const;

public slots:
    void listMembers();
    void listItems();
    void tableClear();
    void addMember();
    void deleteMember();
    void viewMember();
    void saveAll();
    void getItemInfo();
    void setDisplayType();


private:
    Ui::MainWindow *ui;
    MemberList member_list;
    LinkedList<ItemList> item_lists;
    int day_count;

    //Type for functions to display (all: -1, basic: 0, preferred: 1)
    int display_type;
};

#endif // MAINWINDOW_H
