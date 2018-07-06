#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QPushButton;
class Keypad;

class Widget : public QWidget
{
    Q_OBJECT
private:
//    Keypad* keypad;
    QPushButton* createMatrixKalk;
    QPushButton* createNetworkKalk;

private slots:
    void handleNumButtons();
    void handleDotButton();
    void handleAssignmentButton();
    void handleCreateMatrixKalkButton();
    void handleCreateNetworkKalkButton();
    void showWidget();

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
