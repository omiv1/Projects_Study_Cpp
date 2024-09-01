#include <QCoreApplication>
#include <QSet>
#include <QString>
#include <iostream>

using namespace std;

bool isPalindrome(QString& text) {
    QSet<QChar> cleanedText;

    for (QChar c : text) {
        if (c.isLetter()) {
            cleanedText.insert(c.toLower());
        }
    }

    QSet<QChar> reversedText(cleanedText.begin(), cleanedText.end());

    return cleanedText == reversedText;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QString input = "kajak";

    if (isPalindrome(input)) {
        cout << "Napis jest palindromem";
    } else {
        cout << "Napis nie jest palindromem";
    }

    return a.exec();
}
