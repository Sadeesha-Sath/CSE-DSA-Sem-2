#include <cstring>
#include <string>
#include <iostream>
using namespace std;

struct HashTable
{
    int MAX_LENGTH = 4;
    string *password = new string[MAX_LENGTH];

    void intialize_hashtable()
    {
        for (int i = 0; i < 4; i++)
        {
            password[i].clear();
        }
    }
    bool isFull()
    {
        bool full = true;
        int count = 0;
        for (int i = 0; i < MAX_LENGTH; i++)
        {
            if (password[i].empty())
            {
                full = false;
            }
        }
        return full;
    }
    int hashfunc(string user_name)
    {
        int sum = 0;
        int hash = 0;
        // add your code below
        for (int i = 0; i < user_name.length(); i++)
        {
            // Add the ascii values to the sum
            sum += int(user_name[i]);
        }

        hash = sum % MAX_LENGTH;

        return hash;
    }
    bool is_slot_empty(int hash)
    {
        bool empty = password[hash].empty();
        return empty;
    }
    void insert(string user_name, string user_password)
    {
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);
        // add an if condition to complete the code here
        if (empty)
        {
            password[hash] = user_password;
        }
        else
        {
            cout << "The slot is full" << endl;
        }
    }
    void hash_lookup(string user_name)
    {
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);
        // add an if condition to complete the code here
        if (!empty)
        {
            cout << password[hash] << endl;
        }
        else
        {
            cout << "Empty" << endl;
        }
    }
    void delete_item(string user_name)
    {
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);
        if (empty)
        {
            cout << "No item found\n";
        }
        else
        {
            password[hash].clear();
            cout << "User deleted\n";
        }
    }
    void print_hashtable()
    {
        for (int i = 0; i < MAX_LENGTH; i++)
        {
            cout << "[" << i << "]-->" << password[i] << "\n";
        }
    }
};

bool isInt(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
        {
            // Handle if the number is negative
            if (i == 0 && str[0] == '-')
            {
                continue;
            }
            return false;
        }
    }
    return true;
}

int main()
{
    HashTable *hashtbl = new HashTable;
    hashtbl->intialize_hashtable();
    cout << hashtbl->isFull() << "\n";

    int command = 0;
    string user_name;
    string password;
    while (command != -1)
    {
        /* code */
        string cmd;
        cout << "Type command: ";
        cin >> cmd;
        if (!isInt(cmd))
        {
            cout << "Please enter a valid number\n";
            continue;
        }
        command = stoi(cmd);
        switch (command)
        {
        case 1:
            /* insert the new item*/
            cout << "Enter user name: ";
            cin >> user_name;
            cout << "Enter password to be saved: ";
            cin >> password;
            hashtbl->insert(user_name, password);
            break;
        case 2:
            /* delete item */
            cout << "Enter item to be deleted: ";
            cin >> user_name;
            hashtbl->delete_item(user_name);
            break;
        case 3:
            /* hash lookup password*/
            cout << "Enter user name to look up password:";
            cin >> user_name;
            hashtbl->hash_lookup(user_name);
            break;
        case 4:
            hashtbl->print_hashtable();
            break;
        case -1:
            /* hash lookup password*/
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid command\n";
            break;
        }
    }
    return 0;
}
