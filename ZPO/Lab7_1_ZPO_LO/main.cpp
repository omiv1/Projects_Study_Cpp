#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTableWidgetItem>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

#include <vector>

class Car {
public:
    QString brand;
    QString model;
    int year;
    QString VIN;
};

class CarCatalog : public QMainWindow {
    Q_OBJECT

public:
    CarCatalog(QWidget *parent = nullptr) : QMainWindow(parent) {
        setupUI();
    }

private slots:
    void addCar() {
        QString brand = brandLineEdit->text();
        QString model = modelLineEdit->text();
        int year = yearLineEdit->text().toInt();
        QString VIN = VINLineEdit->text();

        Car car;
        car.brand = brand;
        car.model = model;
        car.year = year;
        car.VIN = VIN;
        cars.push_back(car);

        int row = carsTable->rowCount();
        carsTable->insertRow(row);
        carsTable->setItem(row, 0, new QTableWidgetItem(brand));
        carsTable->setItem(row, 1, new QTableWidgetItem(model));
        carsTable->setItem(row, 2, new QTableWidgetItem(QString::number(year)));
        carsTable->setItem(row, 3, new QTableWidgetItem(VIN));

        brandLineEdit->clear();
        modelLineEdit->clear();
        yearLineEdit->clear();
        VINLineEdit->clear();
    }

    void displayCars() {
        carsTable->setRowCount(0);

        for (const auto &car : cars) {
            int row = carsTable->rowCount();
            carsTable->insertRow(row);
            carsTable->setItem(row, 0, new QTableWidgetItem(car.brand));
            carsTable->setItem(row, 1, new QTableWidgetItem(car.model));
            carsTable->setItem(row, 2, new QTableWidgetItem(QString::number(car.year)));
            carsTable->setItem(row, 3, new QTableWidgetItem(car.VIN));
        }
    }

private:
    void setupUI() {
        QWidget *centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);

        QVBoxLayout *layout = new QVBoxLayout(centralWidget);

        brandLineEdit = new QLineEdit(this);
        modelLineEdit = new QLineEdit(this);
        yearLineEdit = new QLineEdit(this);
        VINLineEdit = new QLineEdit(this);

        QLabel *brandLabel = new QLabel("Brand:", this);
        QLabel *modelLabel = new QLabel("Model:", this);
        QLabel *yearLabel = new QLabel("Year:", this);
        QLabel *VINLabel = new QLabel("VIN:", this);

        QPushButton *addCarButton = new QPushButton("Add Car", this);
        QPushButton *displayCarsButton = new QPushButton("Display Cars", this);

        carsTable = new QTableWidget(this);
        carsTable->setColumnCount(4);
        QStringList headers = {"Brand", "Model", "Year", "VIN"};
        carsTable->setHorizontalHeaderLabels(headers);

        connect(addCarButton, &QPushButton::clicked, this, &CarCatalog::addCar);
        connect(displayCarsButton, &QPushButton::clicked, this, &CarCatalog::displayCars);

        layout->addWidget(brandLabel);
        layout->addWidget(brandLineEdit);
        layout->addWidget(modelLabel);
        layout->addWidget(modelLineEdit);
        layout->addWidget(yearLabel);
        layout->addWidget(yearLineEdit);
        layout->addWidget(VINLabel);
        layout->addWidget(VINLineEdit);
        layout->addWidget(addCarButton);
        layout->addWidget(displayCarsButton);
        layout->addWidget(carsTable);
    }

    QLineEdit *brandLineEdit;
    QLineEdit *modelLineEdit;
    QLineEdit *yearLineEdit;
    QLineEdit *VINLineEdit;
    QTableWidget *carsTable;
    std::vector<Car> cars;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    CarCatalog carCatalog;
    carCatalog.show();

    return app.exec();
}

#include "main.moc"
