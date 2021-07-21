#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//4
#include <QMainWindow>
#include <QRect>
#include <QPaintEvent>
#include <QCloseEvent>
#include <QPainter>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QFile>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void selectLevel(int l);
    void mousePressEvent(QMouseEvent* );
    void keyPressEvent(QKeyEvent *);
    void closeEvent(QCloseEvent *);
    void NewGame();
    void EndGame();
    QString dump();
    void setdump(const QString &);

private:
    Ui::MainWindow *ui;
    QRect ** board;
    bool flag[100][100];
    int start_x; //// taracqi verevi
    int start_y; //// dzaxi coordinates
    int size_x, size_y; // et taracqi chapery
    int mode;
    QPair <int, int> level[102][102];
    QPushButton * test;
    QPushButton * close1;
    QPushButton * close2;
    QPushButton * save;
    QPushButton * close3;
    QFile savefile;
    bool help;

public slots:
    void check();
private slots:
    void on_actionNew_triggered();
    void on_actionExit_triggered();
    void on_actionAbout_triggered();
    void on_actionRules_triggered();
    void on_actionOptions_triggered();
    void on_actionSave_triggered();
    void on_actionOpen_triggered();
    void saveOptions();
};

#endif // MAINWINDOW_H
