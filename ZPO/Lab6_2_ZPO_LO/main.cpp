#include <iostream>
#include <string>
#include <C:\Users\lukas\Downloads\boost_1_83_0\boost_1_83_0\boost\multi_index_container.hpp>
#include <C:\Users\lukas\Downloads\boost_1_83_0\boost_1_83_0\boost\multi_index/member.hpp>
#include <C:\Users\lukas\Downloads\boost_1_83_0\boost_1_83_0\boost\multi_index/ordered_index.hpp>

using namespace std;
using namespace boost::multi_index;

struct Contact {
    string name;
    string surname;
    int age;
    string phone;
    string street;
};

struct name_tag {};
struct phone_tag {};
struct street_tag {};

typedef multi_index_container<
        Contact,
        indexed_by<
        ordered_unique<tag<name_tag>, member<Contact, string, &Contact::name>>,
ordered_unique<tag<phone_tag>, member<Contact, string, &Contact::phone>>,
ordered_non_unique<tag<street_tag>, member<Contact, string, &Contact::street>>
>
> ContactsContainer;

class Contacts {
public:
    void addContact(const Contact& contact) {
        auto& name_index = contacts_.get<name_tag>();
        auto& phone_index = contacts_.get<phone_tag>();

        if (phone_index.find(contact.phone) == phone_index.end()) {
            contacts_.insert(contact);
            cout << "Dodano kontakt: " << contact.name << " " << contact.surname << endl;
        } else {
            cout << "Numer telefonu " << contact.phone << " juz istnieje w ksiazce teleadresowej" << endl;
        }
    }

    void removeContactByPhone(const string& phone) {
        auto& phone_index = contacts_.get<phone_tag>();
        auto it = phone_index.find(phone);

        if (it != phone_index.end()) {
            phone_index.erase(it);
            cout << "Usunieto kontakt o numerze telefonu: " << phone << endl;
        } else {
            cout << "Nie znaleziono kontaktu o numerze telefonu: " << phone << endl;
        }
    }

    void findContactsByStreet(const string& street) {
        auto& street_index = contacts_.get<street_tag>();
        auto range = street_index.equal_range(street);

        cout << "Osoby mieszkajace na ulicy " << street << ":" << endl;
        for (auto it = range.first; it != range.second; ++it) {
            cout << it->name << " " << it->surname << endl;
        }
    }

    void displayContacts() const {
        cout << "Zawartosc ksiazki teleadresowej:" << endl;
        for (const auto& contact : contacts_) {
            cout << contact.name << " " << contact.surname << " - "
                 << "Wiek: " << contact.age << ", Telefon: " << contact.phone
                 << ", Ulica: " << contact.street << endl;
        }
    }

private:
    ContactsContainer contacts_;
};

int main() {
    Contacts contactsBook;

    Contact contact1{"John", "Doe", 25, "123-456-789", "Main Street"};
    Contact contact2{"Jane", "Smith", 30, "987-654-321", "Main Street"};
    Contact contact3{"Bob", "Johnson", 40, "111-222-333", "Maple Avenue"};

    contactsBook.addContact(contact1);
    contactsBook.addContact(contact2);
    contactsBook.addContact(contact3);

    contactsBook.findContactsByStreet("Main Street");
    contactsBook.removeContactByPhone("987-654-321");

    contactsBook.displayContacts();

    return 0;
}