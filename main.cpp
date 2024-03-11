#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

// Program 5 (Simple Substitution Cipher)

// Function to check if repeated characters are present
bool repeated_letters(string key)
{
    for (int i = 0; i < key.length(); ++i)
    {
        for (int j = 0; j < key.length(); ++j)
        {
            if (i != j && key[i] == key[j]) // Check if the characters at positions i and j are the same
            {
                return false;
            }
        }
    }
    return true;
}

// Simple Substitution Cipher Function
void  Simple_Substitution_Cipher(string text)
{
    vector<char> alphabet= { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',};
    string key;

    cin.ignore();
    while (true) // While loop to prompt the user to enter a valid key
    {
        cout<<"Enter a key of 5 letters: ";
        getline(cin,key);

        if (key.size() != 5)  // Checking if key length is equal to 5
        {
            cout << "Invalid! Please enter a key of 5 letters"<<endl;
            continue;
        }// while loop to check validity

        else  // Checking if all elements in key are alphabetic characters
        {
            int s = 0;
            for (char x : key)
            {
                if (!isalpha(x))
                {
                    s = 1;
                    break;
                }
            }
            if (s == 1)
            {
                cout << "Invalid! Enter a valid key of characters" << endl;
                continue;
            }
        }
        if (! repeated_letters(key) ) //Checking for repeated characters
        {
            cout<<"Invalid! Please enter a key with no repeated letters"<<endl;
        }
        else
        {
            for (char &x : key)
            {
                x = tolower(x);
            }
            break;
        }
    }

    string exclude= {key[0],key[1],key[2],key[3],key[4]};

    vector <char> cipher_alph;// Creating ciphered alphabetic vector
    for(char i : alphabet)
    {
        if(exclude.find(i)== string::npos)
            cipher_alph.push_back(i);
    }//Removing key elements from alphabet

    // Adding key elements in beginning
    cipher_alph.insert (cipher_alph.begin()+0,key[0]);
    cipher_alph.insert (cipher_alph.begin()+1,key[1]);
    cipher_alph.insert (cipher_alph.begin()+2,key[2]);
    cipher_alph.insert (cipher_alph.begin()+3,key[3]);
    cipher_alph.insert (cipher_alph.begin()+4,key[4]);

    string ciphered;
    for (int w=0 ; w<text.size(); ++w)
    {
        for(int i=0; i<cipher_alph.size(); ++i)
        {
            if(alphabet[i]==tolower(text[w]))
            {
                ciphered.push_back (cipher_alph[i]);// Returning the correspondence index in the Ciphered alphabet
            }
            else if(text [w]==' ')  // Returning space if exists in user's text to ciphered string
            {
                ciphered.push_back(' ');
                break;
            }
        }
    }
    cout<<"===================================="<<endl;
    cout<< "Ciphered text: "<< ciphered<<endl; //Display Ciphered text
    cout<<"===================================="<<endl;
    cout<< "Plain Alphabet:   ";
    for (char i : alphabet) // Display plain alphabet vector
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<< "Ciphered Alphabet:";
    for (char c : cipher_alph) // Display ciphered alphabet vector
    {
        cout<<c<<" ";
    }
    cout<<endl;
    cout<<"===================================="<<endl;

    return ;
}

// Simple Substitution Decipher Function
void  Simple_Substitution_Decipher(string text)
{
    vector<char> alphabet= { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',};
    string key;

    cin.ignore();
    while (true) // While loop to prompt the user to enter a valid key
    {
        cout<<"Enter a key of 5 letters: ";
        getline(cin,key);

        if (key.size() != 5) // Checking if key length is equal to 5
        {
            cout << "Invalid! Please enter a key of 5 letters"<<endl;
            continue;
        }
        else  // Checking if all elements in key are alphabetic characters
        {
            int s = 0;
            for (char x : key)
            {
                if (!isalpha(x))
                {
                    s = 1;
                    break;
                }
            }
            if (s == 1)
            {
                cout << "Invalid! Enter a valid key of characters" << endl;
                continue;
            }
        }
        if (! repeated_letters(key) ) //Checking for repeated characters
        {
            cout<<"Invalid! Please enter a key with no repeated letters"<<endl;
        }
        else
        {
            for (char &x : key)  // In case of user entering upper case letters , convert to lower case
            {
                x = tolower(x);
            }
            break;
        }
    }

    string exclude= {key[0],key[1],key[2],key[3],key[4]};

    vector <char> decipher_alph;// Creating deciphered alphabetic vector
    for(char i : alphabet)
    {
        if(exclude.find(i)== string::npos)
            decipher_alph.push_back(i);
    }//Removing key elements from alphabet

    // Adding key elements in beginning
    decipher_alph.insert (decipher_alph.begin()+0,key[0]);
    decipher_alph.insert (decipher_alph.begin()+1,key[1]);
    decipher_alph.insert (decipher_alph.begin()+2,key[2]);
    decipher_alph.insert (decipher_alph.begin()+3,key[3]);
    decipher_alph.insert (decipher_alph.begin()+4,key[4]);

    string deciphered;
    for (int w=0 ; w<text.size(); ++w)
    {
        for(int i=0; i<decipher_alph.size(); ++i)
        {
            if(decipher_alph[i]==tolower(text[w]))
            {
                deciphered.push_back (alphabet[i]);// Returning the correspondence index in alphabet vector
            }
            else if(text [w]==' ')
            {
                deciphered.push_back(' '); // Returning space if exists in user's text to ciphered string
                break;
            }

        }
    }
    cout<<"===================================="<<endl;
    cout<< "Deciphered text: "<< deciphered<<endl; //Display Ciphered text
    cout<<"===================================="<<endl;
    cout<< "Plain Alphabet:   ";
    for (char i : alphabet) // Display plain alphabet vector
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<< "Deciphered Alphabet:";
    for (char c : decipher_alph) // Display ciphered alphabet vector
    {
        cout<<c<<" ";
    }
    cout<<endl;
    cout<<"===================================="<<endl;

    return ;
}
