#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;


struct Node
{
    string name;
    string phone;
    string mail;
    Node* prev;
    Node* next;
};


Node* head = NULL;
Node* lastDeletedContact = NULL;

string countryCodes[4] = { "+91", "+1", "+44", "+61" };

string makeTextLowerCase(string text)
{
    for (int i = 0; i < text.length(); i++)
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] += 32;
   return text;
}

void getLine(string& text)
{ 
        getline(cin, text);
        while (text.size() == 0)
        getline(cin, text);
}

string encryptText(string data)
{
string result = "";
 for (int i = 0; i < data.length(); i++)
        result += char(data[i] + 3);
         return result;
}

string decryptText(string data)
{
    string result = "";
     for (int i = 0; i < data.length(); i++)
        result += char(data[i] - 3);
          return result;
}


bool isEmailCorrect(string email)
{
    string lower = makeTextLowerCase(email);
    return (lower.find("@gmail.com") != -1 || lower.find("@yahoo.com") != -1 ||
            lower.find("@outlook.com") != -1 || lower.find("@hotmail.com") != -1);
}        

bool isPhoneNumberCorrect(string phone)
{
    if (phone.length() != 10) return false;
        for (char c : phone)
        if (!isdigit(c)) return false;
  return true;
}

Node* makeNode(string name, string phone, string mail)
{
  Node* n = new Node();
  n->name = name;
  n->phone = phone;
  n->mail = mail;
  n->prev = NULL; 
  n->next = NULL;
    return n;
}
  
void saveToFile()
{
    ofstream file("contacts.txt");
    Node* t = head;
    while (t)
    {
        file << t->name << ","
          << encryptText(t->phone) << ","
          << encryptText(t->mail) << endl;  
        t = t->next;






        
