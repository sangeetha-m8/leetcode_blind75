#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isAnagram(char* s, char* t) {
    int count[26] = {0,};

    if (strlen(s) != strlen(t)) {
        return false;
    }

    for (int i = 0; i < strlen(s); i++) {
        if (isalpha((unsigned char)s[i])) {
            char cs = tolower(s[i]);
            count[cs - 'a'] += 1;
        }
    }

    for (int i = 0; i < strlen(t); i++) {
        if (isalpha((unsigned char)t[i])) {
            char ct = tolower(t[i]);
            count[ct - 'a'] -= 1;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0)
            return false;
    }

    return true;
}