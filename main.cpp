#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMenu>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setFixedSize(200, 100);

    QPushButton button("Menu Button", &window);
    button.setGeometry(10, 10, 180, 30);

    QMenu menu(&button);
    QAction *action1 = menu.addAction("Option 1");
    QAction *action2 = menu.addAction("Option 2");
    QAction *action3 = menu.addAction("Option 3");

    QObject::connect(action1, &QAction::triggered, [&]() { qDebug() << "Option 1 selected"; });
    QObject::connect(action2, &QAction::triggered, [&]() { qDebug() << "Option 2 selected"; });
    QObject::connect(action3, &QAction::triggered, [&]() { qDebug() << "Option 3 selected"; });

    button.setMenu(&menu);

    window.show();

    return app.exec();
}
