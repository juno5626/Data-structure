#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include "contact.h"
#include <iostream>


using namespace std;

void Contact::load(string file_name) {
    char c_str[1024];
    strcpy(c_str, file_name.c_str());

    ifstream infile(c_str);
    if (!infile) {
        cerr << "Cannot open" << endl;
        exit(-1);
    }

    string line;
    while (getline(infile, line)) {
        persons[total_num++] = str2person(trim(&line[0]));
    }

    infile.close();
}
    


    // implement here


void Contact::print() {
    // implement here

    for (int i = 0; i < total_num; i++) {
        cout << "[" << persons[i].name << "][" << persons[i].dob.year << persons[i].dob.month << persons[i].dob.day << "][" << persons[i].email << "][" << persons[i].phone << "]" << endl;
    }

}

// implement the other functions here 


Person Contact::str2person(char* line) {
    Person p1;
    char *token;
    int i = 0;

    token = strtok(line, ";");
    while (token) {
        switch (i) {
            case 0: strcpy(p1.name, trim(token)); break;
            case 1: p1.dob = str2date(trim(token)); break;
            case 2: strcpy(p1.email, trim(token)); break;
            case 3: strcpy(p1.phone, trim(token)); break;
        }
        token = strtok(NULL, ";");
        i++;
    }
    return p1;
}


Date Contact::str2date(char* str) {
    Date date;
    char temp[10];
    strncpy(temp, str, 4);
    temp[4] = 0;
    date.year = atoi(temp);
    
    strncpy(temp, str+4, 2);
    temp[2] = 0;
    date.month = atoi(temp);

    strncpy(temp, str+6, 2);
    temp[2] = 0;
    date.day = atoi(temp);

    return date;
}


char* Contact::trim(char* s) {
    char* ptr;
    if (!s) return NULL;
    while (isspace(*s)) s++;
    for (ptr = s + strlen(s) - 1; (ptr >= s) && isspace(*ptr); --ptr);
    *(ptr+1) = '\0';
    return s;
}