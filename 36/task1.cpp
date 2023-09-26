#include <QApplication>
#include <iostream>
#include <QPixmap>
#include <QWidget>
#include <QSlider>
#include <QPainter>
#include <QPaintEvent>
#include <QVBoxLayout>

class CicrcleDraw : public QWidget {
    QPixmap redPixMap;
    QPixmap greenPixMap;
    QPixmap yellowPixMap;
    QPixmap currentPixMap;

public:
    CicrcleDraw(QWidget *parent) : QWidget(parent) {
        greenPixMap = QPixmap("green.png");
        redPixMap = QPixmap("red.png");
        yellowPixMap = QPixmap("yellow.png");

        currentPixMap = greenPixMap;

        // setFixedSize(200, 250);
    }

    QSize minimumSizeHint() const override {
        return QSize(100, 100);
    }

    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.drawPixmap(rect(), currentPixMap);
    }

public slots:
    void setRed() {
        currentPixMap = redPixMap;
        update();
    }

    void setGreen() {
        currentPixMap = greenPixMap;
        update();
    }

    void setYellow() {
        currentPixMap = yellowPixMap;
        update();
    }
};

int main (int argc, char* argv[])
{
    QApplication app(argc, argv);
    auto *window = new QWidget;
    auto *layout = new QVBoxLayout(window);
    auto *circle = new CicrcleDraw(window);
    auto *slider = new QSlider(Qt::Horizontal, window);
    window->setFixedSize(200, 250);
    layout->addWidget(circle);
    layout->addWidget(slider);
    slider->setRange(0, 99);
    QObject::connect(slider, &QSlider::valueChanged, [slider, circle](int newValue){
        const auto value = slider->value();
        if (value >= 0 && value < 33)
            circle->setGreen();
        else if (value >= 33 && value < 66)
            circle->setYellow();
        else
            circle->setRed();
    });

    window->show();

    return app.exec();   
}
