//
// Created by lukas on 19.11.2023.
//

#ifndef LAB5_2_ZPO_LO_DICTIONARY_H
#define LAB5_2_ZPO_LO_DICTIONARY_H

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Dictionary {
private:
    map<string, string> words;

public:
    Dictionary() {}

    void addWord(string word, string translation){
        if (words.find(word) == words.end()) {
            words[word] = translation;
            cout << "Dodano nowe slowo: " << word << endl;
        } else {
            cout << "Slowo juz istnieje w slowniku: " << word << endl;
        }
    }

    void removeWord(string word){
        auto it = words.find(word);
        if (it != words.end()) {
            words.erase(it);
            cout << "Usunieto slowo: " << word << endl;
        } else {
            cout << "Slowo nie istnieje w slowniku: " << word << endl;
        }
    }

    void showDictionary(){
        cout << "Slownik:" << endl;
        for (auto entry : words) {
            cout << entry.first << " -> " << entry.second << endl;
        }
    }

    void showTranslation(string word){
        auto it = words.find(word);
        if (it != words.end()) {
            cout << "Tlumaczenie dla slowa " << word << ": " << it->second << endl;
        } else {
            cout << "Brak tlumaczenia dla slowa " << word << "." << endl;
        }
    }

    void showSortedDictionary(){
        vector<pair<string, string>> sortedWords(words.begin(), words.end());

        sort(sortedWords.begin(), sortedWords.end(), [](auto a, auto b) {
            return a.second > b.second;
        });

        cout << "Slownik posortowany wg tlumaczenia (od z do a):" << endl;
        for (auto entry : sortedWords) {
            cout << entry.first << " -> " << entry.second << endl;
        }
    }
};

#endif //LAB5_2_ZPO_LO_DICTIONARY_H
