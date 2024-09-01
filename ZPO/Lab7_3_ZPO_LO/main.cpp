#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QMap>
#include <QPair>
#include <QMessageBox>

class CountryApp : public QMainWindow {
    Q_OBJECT

public:
    CountryApp(QWidget *parent = nullptr) : QMainWindow(parent) {
        setupUI();
    }

private slots:
    void addCountry() {
        QString name = nameLineEdit->text();
        bool ok;
        int population = populationLineEdit->text().toInt(&ok);

        if (ok && population > 0) {
            countries[name] = population;
            updateList();
            clearInputFields();
        } else {
            QMessageBox::warning(this, "Invalid Input", "Please enter a valid country name and population.");
        }
    }

    void showAllCountries() {
        updateList();
    }

    void showCountriesInRange() {
        int minPopulation = minPopulationLineEdit->text().toInt();
        int maxPopulation = maxPopulationLineEdit->text().toInt();

        QList<QString> countriesInRange;
        for (auto it = countries.constBegin(); it != countries.constEnd(); ++it) {
            if (it.value() >= minPopulation && it.value() <= maxPopulation) {
                countriesInRange.append(it.key());
            }
        }

        updateList(countriesInRange);
    }

    void removeCountry() {
        QString name = removeLineEdit->text();
        if (countries.contains(name)) {
            countries.remove(name);
            updateList();
            clearInputFields();
        } else {
            QMessageBox::warning(this, "Not Found", "Country not found.");
        }
    }

    void sortCountries() {
        QList<QPair<QString, int>> sortedCountries;
        for (auto it = countries.constBegin(); it != countries.constEnd(); ++it) {
            sortedCountries.append(qMakePair(it.key(), it.value()));
        }

        if (sortAscendingRadio->isChecked()) {
            std::sort(sortedCountries.begin(), sortedCountries.end(), comparePopulationAscending);
        } else {
            std::sort(sortedCountries.begin(), sortedCountries.end(), comparePopulationDescending);
        }

        updateList(sortedCountries);
    }

private:
    void setupUI() {
        QWidget *centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);

        QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

        QFormLayout *formLayout = new QFormLayout;
        nameLineEdit = new QLineEdit;
        populationLineEdit = new QLineEdit;
        formLayout->addRow("Country Name:", nameLineEdit);
        formLayout->addRow("Population:", populationLineEdit);
        mainLayout->addLayout(formLayout);

        QPushButton *addButton = new QPushButton("Add Country");
        connect(addButton, &QPushButton::clicked, this, &CountryApp::addCountry);
        mainLayout->addWidget(addButton);

        mainLayout->addWidget(new QLabel("All Countries:"));

        countryListWidget = new QListWidget;
        mainLayout->addWidget(countryListWidget);

        QPushButton *showAllButton = new QPushButton("Show All Countries");
        connect(showAllButton, &QPushButton::clicked, this, &CountryApp::showAllCountries);
        mainLayout->addWidget(showAllButton);

        mainLayout->addWidget(new QLabel("Filter Countries by Population Range:"));

        QFormLayout *rangeLayout = new QFormLayout;
        minPopulationLineEdit = new QLineEdit;
        maxPopulationLineEdit = new QLineEdit;
        rangeLayout->addRow("Min Population:", minPopulationLineEdit);
        rangeLayout->addRow("Max Population:", maxPopulationLineEdit);
        mainLayout->addLayout(rangeLayout);

        QPushButton *rangeButton = new QPushButton("Show Countries in Range");
        connect(rangeButton, &QPushButton::clicked, this, &CountryApp::showCountriesInRange);
        mainLayout->addWidget(rangeButton);

        mainLayout->addWidget(new QLabel("Remove Country:"));

        removeLineEdit = new QLineEdit;
        mainLayout->addWidget(removeLineEdit);

        QPushButton *removeButton = new QPushButton("Remove Country");
        connect(removeButton, &QPushButton::clicked, this, &CountryApp::removeCountry);
        mainLayout->addWidget(removeButton);

        mainLayout->addWidget(new QLabel("Sort Countries by Population:"));

        sortAscendingRadio = new QRadioButton("Ascending");
        sortDescendingRadio = new QRadioButton("Descending");
        sortAscendingRadio->setChecked(true);

        QVBoxLayout *sortRadioLayout = new QVBoxLayout;
        sortRadioLayout->addWidget(sortAscendingRadio);
        sortRadioLayout->addWidget(sortDescendingRadio);

        mainLayout->addLayout(sortRadioLayout);

        QPushButton *sortButton = new QPushButton("Sort Countries");
        connect(sortButton, &QPushButton::clicked, this, &CountryApp::sortCountries);
        mainLayout->addWidget(sortButton);

        updateList();
    }

    void updateList(const QList<QString> &filteredCountries = {}) {
        countryListWidget->clear();

        QList<QString> keys = filteredCountries.isEmpty() ? countries.keys() : filteredCountries;
        for (const QString &country : keys) {
            QString itemText = QString("%1: %2").arg(country).arg(countries[country]);
            countryListWidget->addItem(itemText);
        }
    }

    void clearInputFields() {
        nameLineEdit->clear();
        populationLineEdit->clear();
        minPopulationLineEdit->clear();
        maxPopulationLineEdit->clear();
        removeLineEdit->clear();
    }

    static bool comparePopulationAscending(const QPair<QString, int> &a, const QPair<QString, int> &b) {
        return a.second < b.second;
    }

    static bool comparePopulationDescending(const QPair<QString, int> &a, const QPair<QString, int> &b) {
        return a.second > b.second;
    }

    QLineEdit *nameLineEdit;
    QLineEdit *populationLineEdit;
    QListWidget *countryListWidget;
    QLineEdit *minPopulationLineEdit;
    QLineEdit *maxPopulationLineEdit;
    QLineEdit *removeLineEdit;
    QRadioButton *sortAscendingRadio;
    QRadioButton *sortDescendingRadio;

    QMap<QString, int> countries;
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CountryApp countryApp;
    countryApp.show();
    return a.exec();
}

#include "main.moc"
