#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>

using namespace std;

template <typename T>
void displayStatistics(const vector<T>& data) {
    if (data.empty()) {
        cout << "Vector jest pusty" << endl;
        return;
    }

    //srednia arytmetyczna
    double sum = accumulate(data.begin(), data.end(), 0.0);
    double mean = sum / data.size();

    //medianę
    vector<T> sortedData = data;
    sort(sortedData.begin(), sortedData.end());
    size_t size = sortedData.size();
    T median = (size % 2 == 0) ? (sortedData[size / 2 - 1] + sortedData[size / 2]) / 2.0 : sortedData[size / 2];

    auto isSmallerThanMean = bind(less<T>(), placeholders::_1, mean);
    auto isBetweenMeanAndMedian = bind(logical_and<bool>(),
                                       bind(greater<T>(), placeholders::_1, mean),
                                       bind(less<T>(), placeholders::_1, median));
    auto isPositive = bind(greater<T>(), placeholders::_1, 0);

    cout << "Elementy mniejszy niz srednia (" << mean << "): ";
    copy_if(data.begin(), data.end(), ostream_iterator<T>(cout, " "), isSmallerThanMean);
    cout << endl;

    cout << "Elementy pomiedzy srednia a mediana (" << mean << " - " << median << "): ";
    copy_if(data.begin(), data.end(), ostream_iterator<T>(cout, " "), isBetweenMeanAndMedian);
    cout << endl;

    cout << "Dodatnie elementy: ";
    copy_if(data.begin(), data.end(), ostream_iterator<T>(cout, " "), isPositive);
    cout << endl;
}

int main() {
    vector<int> intVector = {1, 2, -3, 4, 5, -6, 7, 8, 9};
    vector<double> doubleVector = {1.5, 2.0, -3.5, 4.2, 5.1, -6.8, 7.3, 8.9, 9.7};

    cout << "Int vector:" << endl;
    displayStatistics(intVector);

    cout << "\nDouble vector:" << endl;
    displayStatistics(doubleVector);

    return 0;
}
