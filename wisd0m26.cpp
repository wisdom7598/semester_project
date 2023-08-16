#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Contact {
    public:
        string name;
        string phone;
        string email;
        string address;
};

void addContact(Contact contacts[], int &size) {
    Contact newContact;
    cout << "Enter name: ";
    getline(cin, newContact.name);
    cout << "Enter phone number: ";
    getline(cin, newContact.phone);
    cout << "Enter email address: ";
    getline(cin, newContact.email);
    cout << "Enter address: ";
    getline(cin, newContact.address);
    contacts[size] = newContact;
    size++;
}

void displayContacts(Contact contacts[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Name: " << contacts[i].name << endl;
        cout << "Phone: " << contacts[i].phone << endl;
        cout << "Email: " << contacts[i].email << endl;
        cout << "Address: " << contacts[i].address << endl;
        cout << endl;
    }
}

void saveContacts(Contact contacts[], int size) {
    ofstream file("contacts.txt");
    for (int i = 0; i < size; i++) {
        file << contacts[i].name << endl;
        file << contacts[i].phone << endl;
        file << contacts[i].email << endl;
        file << contacts[i].address << endl;
    }
}

void loadContacts(Contact contacts[], int &size) {
    ifstream file("contacts.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            Contact contact;
            contact.name = line;
            getline(file, line);
            contact.phone = line;
            getline(file, line);
            contact.email = line;
            getline(file, line);
            contact.address = line;
            contacts[size] = contact;
            size++;
        }
        file.close();
    }
}

int main() {
    Contact contacts[100];
    int size = 0;

    loadContacts(contacts, size);

    while (true) {
        cout << "1. Add Contact" << endl;
        cout << "2. Display Contacts" << endl;
        cout << "3. Save Contacts" << endl;

        int choice;
        cin >> choice;

        cin.ignore();

        switch (choice) {
            case 1:
                addContact(contacts, size);
                break;

            case 2:
                displayContacts(contacts, size);
                break;

            case 3:
                saveContacts(contacts, size);
                break;

            default:
                return 0;
                break;
        }
    }

    return 0;
}
