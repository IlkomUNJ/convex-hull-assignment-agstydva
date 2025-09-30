#include "mainwindow.h"
#include "drawingcanvas.h"
#include <QVBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Computer Graphic Simulation");
    resize(900, 600);

    QWidget *mainContainer = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(mainContainer);

    canvas = new DrawingCanvas(this);

    QPushButton *pushButtonDraw = new QPushButton("Run Simulation ConvexHull", this);
    QPushButton *pushButtonClear = new QPushButton("Clear Canvas", this);
    QPushButton *pushButtonSlowConvex = new QPushButton("Run Simulation SlowConvex", this);

    QString buttonStyle = "QPushButton {"
                          "    background-color: #4CAF50;"
                          "    color: white;"
                          "    border: 1px solid #387B3B;"
                          "    padding: 10px 20px;"
                          "    border-radius: 5px;"
                          "    font-weight: bold;"
                          "}"
                          "QPushButton:hover {"
                          "    background-color: #45A049;"
                          "}";

    QString clearStyle = "QPushButton {"
                         "    background-color: #f44336;"
                         "    color: white;"
                         "    border: 1px solid #D32F2F;"
                         "    padding: 10px 20px;"
                         "    border-radius: 5px;"
                         "    font-weight: bold;"
                         "}"
                         "QPushButton:hover {"
                         "    background-color: #D32F2F;"
                         "}";

    // Warna Biru untuk ConvexHull
    pushButtonDraw->setStyleSheet(buttonStyle.replace("#4CAF50", "#2196F3").replace("#45A049", "#1E88E5"));
    // Warna Oranye untuk SlowConvex
    pushButtonSlowConvex->setStyleSheet(buttonStyle.replace("#4CAF50", "#FF9800").replace("#45A049", "#FB8C00"));
    // Warna Merah untuk Clear
    pushButtonClear->setStyleSheet(clearStyle);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(pushButtonDraw);
    buttonLayout->addWidget(pushButtonSlowConvex);
    buttonLayout->addWidget(pushButtonClear);

    mainLayout->addWidget(canvas);
    mainLayout->addLayout(buttonLayout);

    setCentralWidget(mainContainer);

    connect(pushButtonDraw, &QPushButton::clicked, canvas, &DrawingCanvas::CalculateConvexHull);
    connect(pushButtonClear, &QPushButton::clicked, canvas, &DrawingCanvas::ClearCanvas);
    connect(pushButtonSlowConvex, &QPushButton::clicked, canvas, &DrawingCanvas::SlowConvex);
}
