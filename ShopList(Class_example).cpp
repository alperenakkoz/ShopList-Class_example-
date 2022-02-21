#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class shopList {

private:
    map<string, int> row;
    map<string, int> mark;

public:
    void printList();
    void insertt(string, int);
    void markk(string);
    void edit(string, int);
    void undo(string); 
};

void shopList::printList() {
    cout << endl;
    for (const auto& a : row) {
        cout << a.first << "    " << a.second << endl;
    }
}

void shopList::insertt(string name, int amount) {
    row.insert(pair<string, int>(name, amount));
}

void shopList::edit(string name, int amount) {
    row[name] = amount;
}

void shopList::markk(string name) {
    mark.insert(pair<string, int>(name, row[name]));
    row.erase(name);
}

void shopList::undo(string name) {
    row.insert(pair<string, int>(name, mark[name]));
    mark.erase(name);
}


int main() {

    int number, amount;
    string name;
    vector<shopList> instances;
    while (true) {
        cout << "Press one of these" << endl;
        cout << "1- Show lists" << endl << "2- Delete list" << endl << "3- Create new list" << endl << "4- Select list" << endl;
        cin >> number;
        switch (number) {
        case 1:
            if (instances.empty() == true)
                cout << "There is no list" << endl;
            else {
                for (int i = 0; i < instances.size(); i++) {
                    cout << endl << "List " << i + 1 << endl;
                    instances[i].printList();
                    cout << endl;
                }
            }
            break;
        case 2:
            cout << "Just enter the list number. If you want to go back press 0" << endl;
            int del;
            cin >> del;
            if (del == 0) break;
            if (del > 0 && del <= instances.size())
                instances.erase(instances.begin() + del - 1);
            else
                cout << "there is no list named like that" << endl;
            break;
        case 3:
            instances.emplace_back();
            break;
        case 4:
            cout << "Just enter the list number. If you want to go back press 0" << endl;
            int sel;
            cin >> sel;
            if (sel == 0) break;
            if (sel > 0 && sel <= instances.size()) {
                bool decision = true;
                while (decision) {
                    cout << endl << "1- Insert list" << endl << "2- Delete product from list" << endl << "3- Edit product from list(edits only amount)" << endl << "4- Undo" << endl <<
                        "5- Print List" << endl << "6- Return main menu" << endl;
                    int number2;
                    cin >> number2;
                    switch (number2) {
                    case 1:
                        cout << endl << "If you want to exit press 0" << endl;
                        while (true) {
                            cout << "Name : ";
                            cin >> name;
                            if (name == "0")
                                break;
                            cout << "Amount : ";
                            cin >> amount;
                            if (amount == 0)
                                break;
                            instances[sel - 1].insertt(name, amount);
                        }
                        break;
                    case 2:

                        cout << endl << "If you want to exit press 0" << endl;

                        cout << "Name : ";
                        cin >> name;
                        if (name == "0")
                            break;
                        instances[sel - 1].markk(name);
                        break;
                    case 3:

                        cout << endl << "If you want to exit press 0" << endl;

                        cout << "Name : ";
                        cin >> name;
                        if (name == "0")
                            break;
                        cout << "Amount : ";
                        cin >> amount;
                        if (amount == 0)
                            break;
                        instances[sel - 1].edit(name, amount);
                        break;

                    case 4:
                        cout << endl << "If you want to exit press 0" << endl;
                        cout << "Write name of the product" << endl;
                        cin >> name;
                        if (name == "0")
                            break;
                        instances[sel - 1].undo(name);
                        break;
                    case 5:
                        instances[sel - 1].printList();
                        break;
                    case 6:
                        decision = false;
                        break;
                    default:
                        cout << endl << "Please enter 1 or 2 or 3 or 4 or 5 or 6" << endl;

                    }
                }

            }
            else
                cout << "there is no list named like that" << endl;
            break;
        default:
            cout << endl << "Please enter 1 or 2 or 3 or 4" << endl;
        }
        cout << endl;
    }

    return 0;
}
