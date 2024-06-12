#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class Contact {
public:
    string name;
    string birthday;
    string email;
    string phone_number;

    Contact() {}
    Contact(const string& n, const string& b, const string& e, const string& p)
        : name(n), birthday(b), email(e), phone_number(p) {}

    string to_string() const {
        return name + "; " + birthday + "; " + email + "; " + phone_number;
    }

    void print() const {
        cout << to_string() << endl;
    }
};
class ContactManager {
private:
    Contact contacts[100]; // 최대 100개의 연락처를 저장할 수 있는 배열
    int contact_count; // 현재 저장된 연락처의 수

public:
    ContactManager() : contact_count(0) {}

    void load(const string& filename) {
        ifstream infile(filename.c_str());
        if (!infile) {
            cout << "Failed to open file: " << filename << endl;
            return;
        }
        string line;
        while (getline(infile, line)) {
            string name, birthday, email, phone_number;
            size_t pos1 = line.find(';');
            size_t pos2 = line.find(';', pos1 + 1);
            size_t pos3 = line.find(';', pos2 + 1);

            if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos) {
                cout << "Incorrect format in line: " << line << endl;
                continue;
            }

            name = line.substr(0, pos1);
            birthday = line.substr(pos1 + 1, pos2 - pos1 - 1);
            email = line.substr(pos2 + 1, pos3 - pos2 - 1);
            phone_number = line.substr(pos3 + 1);

            if (contact_count < 100) {
                contacts[contact_count++] = Contact(name, birthday, email, phone_number);
            } else {
                cout << "Contact list is full" << endl;
                break;
            }
        }

        infile.close();
    }

    void save(const string& filename) const {
        ofstream outfile(filename.c_str());
        if (!outfile) {
            cout << "Failed to open file: " << filename << endl;
            return;
        }

        for (int i = 0; i < contact_count; ++i) {
            outfile << contacts[i].to_string() << endl;
        }

        outfile.close();
    }

    void insert(const Contact& contact) {
        if (contact_count < 100) {
            contacts[contact_count++] = contact;
        } else {
            cout << "Contact list is full" << endl;
        }
    }

    void delete_contact(const string& name) {
        for (int i = 0; i < contact_count; ++i) {
            if (contacts[i].name == name) {
                for (int j = i; j < contact_count - 1; ++j) {
                    contacts[j] = contacts[j + 1];
                }
                --contact_count;
                break;
            }
        }
    }

    void retrieve_by_name( string& name)  {
        for (int i = 0; i < contact_count; ++i) {
            if (contacts[i].name == name) {
                getchar();
                cout<<"name  ";
                getline(cin, contacts[i].name);
                cout<<"birthday  ";
                cin>>contacts[i].birthday;
                cout<<"email  ";
                cin>>contacts[i].email;
                cout<<"phone_number  ";
                cin>>contacts[i].phone_number;
                return;
            }
        }
        cout << "Contact not found" << endl;
    }

    void retrieve_by_email( string& email)  {
        for (int i = 0; i < contact_count; ++i) {
            if (contacts[i].email == email) {
                getchar();
                cout<<"name  ";
                getline(cin, contacts[i].name);
                cout<<"birthday  ";
                cin>>contacts[i].birthday;
                cout<<"email  ";
                cin>>contacts[i].email;
                cout<<"phone_number  ";
                cin>>contacts[i].phone_number;
                return;
            }
        }
        cout << "Contact not found" << endl;
    }

    void sort_by_name() {
        for (int i = 0; i < contact_count - 1; ++i) {
            for (int j = i + 1; j < contact_count; ++j) {
                if (contacts[i].name > contacts[j].name) {
                    Contact temp = contacts[i];
                    contacts[i] = contacts[j];
                    contacts[j] = temp;
                }
            }
        }
    }

    void sort_by_birthday() {
        for (int i = 0; i < contact_count - 1; ++i) {
            for (int j = i + 1; j < contact_count; ++j) {
                if (contacts[i].birthday > contacts[j].birthday) {
                    Contact temp = contacts[i];
                    contacts[i] = contacts[j];
                    contacts[j] = temp;
                }
            }
        }
    }

    void print() const {
        for (int i = 0; i < contact_count; ++i) {
            contacts[i].print();
        }
    }
};


int main() {
    ContactManager manager;
    int no, no2;

    manager.load("contact.txt");

    while(1){  
        cout<<"====MENU===="<<endl;
        cout<<"1: print  2: add  3: rewrite  4: sort  5: delete  6: save  7: quit"<<endl;
        cin>>no;

        if(no==1){
            cout << "All Contacts:" << endl;
            manager.print();
        }else if(no==2){
            Contact temp_c;
            getchar();
            cout<<"name  ";
            getline(cin, temp_c.name);
            cout<<"birthday  ";
            cin>>temp_c.birthday;
            cout<<"email  ";
            cin>>temp_c.email;
            cout<<"phone_number  ";
            cin>>temp_c.phone_number;
            
            manager.insert(temp_c);
        }else if(no==3){
            cout<<"1:by name  2:by email";
            cin>>no2;
            if(no2==1){
                string temp;
                cout << "\nRetrieve by Name" << endl;
                cin>>temp;
                manager.retrieve_by_name(temp);
            }else{
                string temp;
                cout << "\nRetrieve by Email" << endl;
                manager.retrieve_by_email(temp);
            }

        }else if(no==4){
            cout<<"1:by name  2:by birthday";
            cin>>no2;
            if(no2==1){
                manager.sort_by_name();
            }else{
                manager.sort_by_birthday();
            }
        }else if(no==5){
            string temp;
            manager.print();
            cout<<"name you want to delete:";
            cin>>temp;
            manager.delete_contact(temp);
        }else if(no==6){
            cout << "\nSaved Contacts:" << endl;
            manager.save("contact.txt");
        }else{
            break;
        }
            
    

    }

    return 0;
}

