#include <QApplication>
#include <iostream>
#include <QTimer>

class Printer : public QObject {
public slots:
    void printFinished() {
        std::cout << "Finished" << std::endl;
    }
};

int main (int argc, char* argv[])
{
    QApplication app(argc, argv);

    QTimer myTimer;
    Printer myPrinter;

    QObject::connect(&myTimer, &QTimer::timeout, &myPrinter, &Printer::printFinished);
    myTimer.start(1000);
    QApplication::exec();

    return 0;   
}
