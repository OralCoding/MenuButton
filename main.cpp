#include <QApplication>
#include <QtWidgets>

class ArrowButton : public QPushButton {
    Q_OBJECT

public:
    ArrowButton(QWidget *parent = nullptr) : QPushButton(parent) {
        setStyleSheet("text-align: left; padding-left: 10px;");
        setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        setFixedHeight(30);

        const auto arrow = QString::fromWCharArray(L"\25BC");
        arrowLabel = new QLabel(arrow);
        arrowLabel->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
        arrowLabel->setFixedSize(30, 30);

        connect(this, &QPushButton::clicked, this, &ArrowButton::toggleMenu);

        menu = new QMenu;
        menu->addAction("메뉴 항목 1");
        menu->addAction("메뉴 항목 2");
        menu->addAction("메뉴 항목 3");
    }

private slots:
    void toggleMenu() {
        if (!menu->isVisible()) {
            menu->popup(mapToGlobal(QPoint(0, -menu->sizeHint().height())));
        } else {
            menu->hide();
        }
    }

private:
    QLabel *arrowLabel;
    QMenu *menu;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout;

    ArrowButton *arrowButton = new ArrowButton;
    layout->addWidget(arrowButton);

    window.setLayout(layout);
    window.setWindowTitle("Arrow Button Example");
    window.show();

    return app.exec();
}
