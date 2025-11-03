#include <iostream>
using namespace std;

class Node{

public:
    string cNum;
    string cName;
    Node* next;

    Node(string num, string name){
        cNum = num;
        cName = name;
        next = nullptr;
    }
};

class ContactInfo{

public:
    Node* head;
    Node* tail;

    ContactInfo(){
        head = tail = nullptr;
    }

    void addContact(string num, string name){
        Node* newNode = new Node(num, name);
        if(head == nullptr){
            head = tail = newNode;
            return;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteContact(string val){
        if (!head) {
            cout << "Contact list is empty!\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp) {
            bool match = (!val.empty()) && ((temp->cName == val) || (temp->cNum == val));
            if (match) {
                if (temp == head) {
                    head = head->next;
                    if (temp == tail) tail = nullptr;
                    delete temp;
                } else {
                    prev->next = temp->next;
                    if (temp == tail) tail = prev;
                    delete temp;
                }
                cout << "Contact deleted successfully.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Contact not found.\n";
    }


    void display(){
        Node* temp = head;
        int count = 1;
        cout << endl;
        while(temp != nullptr){
            cout << count << ". \n\tName: " << temp->cName << "\n\tNo: " << temp->cNum << endl;
            temp = temp->next;
            count++;
        }
        cout << endl;
    }

    Node* search(string val = ""){
        Node* temp = head;
        while (temp) {
            if ((!val.empty()) && ((temp->cNum == val) || temp->cName == val))
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void sortContacts(bool byName = true) {
        if (!head || !head->next) return;
        
        bool swapped;
        do {
            swapped = false;
            Node* temp = head;
            while (temp->next) {
                bool shouldSwap = false;

                if (byName) {
                    if (temp->cName > temp->next->cName)
                        shouldSwap = true;
                } else {
                    long long num1 = stoll(temp->cNum);
                    long long num2 = stoll(temp->next->cNum);
                    if (num1 > num2)
                        shouldSwap = true;
                }

                if (shouldSwap) {
                    swap(temp->cName, temp->next->cName);
                    swap(temp->cNum, temp->next->cNum);
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }


    int size(){
        Node* temp = head;
        int count = 0;
        while(temp){
            temp = temp->next;
            count++;
        }
        return count;
    }

    ~ContactInfo(){
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};
int main() {
    ContactInfo contact;
    int choice;
    string name, number;

    do {
        cout << "\n===== 📞 CONTACT BOOK MENU =====\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search any Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Sort Contacts\n";
        cout << "6. Total Contacts\n";
        cout << "0. Exit\n";
        cout << "===============================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin.ignore();
                cin >> name;
                cout << "Enter number: ";
                cin.ignore();
                cin >> number;
                contact.addContact(number, name);
                cout << "Contact added successfully!\n";
                break;

            case 2:
                cout << "\nAll Contacts:\n";
                contact.display();
                break;

            case 3:
                cout << "Enter Name or Number to search: ";
                cin.ignore();
                cin >> name;
                if (auto res = contact.search(name))
                    cout << "Found -> " << res->cName << ": " << res->cNum << endl;
                else
                    cout << "Contact not found.\n";
                break;

            case 4:
                cout << "Enter name or number to delete: ";
                cin.ignore();
                getline(cin, name); // reuse variable
                contact.deleteContact(name); // handles both internally
                break;

            case 5:
                contact.sortContacts();
                cout << "Contacts sorted by Name successfully!\n";
                break;

            case 6:
                cout << "Total contacts: " << contact.size() << endl;
                break;

            case 0:
                cout << "Exiting Contact Book. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}