#include<iostream>
#include <list>
#include <string>

using namespace std;

// Define our Hash Class
class Hash{

    // Our modulo variable
    int m;

    // Our Hash Table created with list
    list<int> *table;

    // Define our public variables
    public: 

    // Our Constructor
    Hash(int m);
    
    // Our Hash Functions
    void Insert (int key); // Insert a key
    void Delete(int key); // Delete a key
    void Search(int key); // Search a key
    void Print(); // Print our Hash Table

    // Our HashFunction Function with modulo
    int HashFunction(int key){
        return (key%m);
    }
};

// Hash Class
Hash::Hash (int h){

    // Set a pointer to m equal to h 
    this->m = h;

    // Create a new table with h
    table = new list<int>[h];
}

//Hash Insertion Function
void Hash::Insert(int key){
    // Define our index by placing our key through our Hash Function
    int idx = HashFunction(key);

    // Define our Hash table with the key variable
    table[idx].push_front(key);
}

// Hash Search Function
void Hash::Search(int key){     
    // Define our index by placing our key through our Hash Function
    int idx = HashFunction(key);

    // Predefine our j
    list <int> :: iterator j;
    
    // Predefine our i
    int i = 0;

    // From the beginning to end of our table
    for (j = table[idx].begin(); j != table[idx].end(); j++){

        // If *j == key
        if (*j == key){

            // We tell the user we found the key
            cout << key << ":" << "FOUND_AT" << idx << "," << i << ";" << endl;

            // And return the function
            return;
        }
        
        // Also iterate i to ouput the coordinates properly
        i++;

    }

    // Otherwise we tell the user it was not found
    cout << key << ":" << "NOT_FOUND;" << endl;
}

// Hash Delete Function
void Hash::Delete(int key){

    // Define our index by placing our key through our Hash Function
    int idx = HashFunction(key);

    // Predefine our j
    list <int> :: iterator j;

    // From the beginning to the end of our table
    for (j = table[idx].begin(); j != table[idx].end(); j++){

        // If we find the key
        if (*j == key){

            // And we aren't at the end of the table
            if (j != table[idx].end()){

                // We erase it from our table
                table[idx].erase(j);

                // And tell the user the key was Deleted
                cout << key << ":" << "DELETED" << ";" << endl;

                // And return the function 
                return; 
            }

        }


    }

    // Otherwise we tell the user the Delete Failed
    cout << key << ":" << "DELETE_FAILED;" << endl;

}

// Hash Print Function
void Hash::Print(){

    // Predefine our j
    list <int> :: iterator j;

    // From i to our m...
    for (int i = 0; i < m; i++){

        // We print out our i
        cout << i << ":";

        // And print our our resulting table
        for (j = table[i].begin(); j != table[i].end(); j++){

            // We also print out each index/pointer to hash table
            cout << *j << "->";
        }

        // And print a new line
        cout << ";" << endl;

    }
}


int main(){

    // Our modulo variable/size of hash
    int m;

    // Ask User to insert modulo variable/size of hash
    cin >> m;

    // Create our hash with our modulo variable
    Hash h(m);

    // Create our user input and make it to some random char
    string UserInput;

    // Until the user inputs the letter "e" to "end" the program
    while (UserInput != "e"){

        // Get our UserInput
        getline(cin,UserInput);

        // Create our substrings to find the number after i, d, or s
        string inserted;
        string deleted;
        string searched; 
            
        // Initialize Check Variable to be 0
        int check = 0;

        // Our number variable to set equal to our atoi
        int num;    

        // Intialize the length of our entire string
        int length;

        // Find the length of the string
        length = UserInput.size();

        // If the user inputs "i" with a number
        if (check == UserInput.find("i")){

            // Set our inserted to become a substring to any number after our check
            inserted = UserInput.substr(check+1, length);

            // Convert our substring to a number
            num = atoi(inserted.c_str());

            // We insert that number into our hash table
            h.Insert(num);
        }

        // Otherwise if the user inputs "d" with a number
        else if(check == UserInput.find("d")){

            // Set our inserted to become a substring to any number after our check
            deleted = UserInput.substr(check+1, length);

            // Convert our substring to a number
            num = atoi(deleted.c_str());

            // We delete that number from our hash table
            h.Delete(num);
        }

        // Otherwise if the user inputs "s" with a number
        else if(check == UserInput.find("s")){

            // Set our inserted to become a substring to any number after our check
            searched = UserInput.substr(check+1, length);

            // Convert our substring to a number
            num = atoi(searched.c_str());

            // We search that number in our hash table
            h.Search(num);
        }

        // Otherwise if the user inputs "o"
        else if(check == UserInput.find("o")){
            // We print out or "output" our hash table
            h.Print();
        }
            
    }


    // End program
    return 0;
}