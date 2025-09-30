#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "drawingcanvas.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    DrawingCanvas *canvas;
    bool value = true;

signals:
};

#endif // MAINWINDOW_H
