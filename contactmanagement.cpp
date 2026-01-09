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
