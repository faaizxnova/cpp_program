#include <iostream>

using namespace std;

const int MAX_LEN = 1000;
const int MAX_WORDS = 100;
const int THRESHOLD = 3;  

int getLength(char str[]) {
    int count = 0;
    while (str[count] != '\0') count++;
    return count;
}


void copyString(char source[], char destination[]) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}


void toUpper(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
}

void toLower(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;    
}


bool containsSubstring(char text[], char sub[]) {
    int n = getLength(text);
    int m = getLength(sub);
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) if (text[i + j] != sub[j]) break;
        if (j == m) return true;
    }
    return false;
}


void reverseWords(char str[]) {
    int start = 0, n = getLength(str);
    for (int i = 0; i <= n; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            int end = i - 1;
            while (start < end) {
                char temp = str[start];
                str[start] = str[end];
                str[end] = temp;
                start++;
                end--;
            }
            start = i + 1;
        }
    }
}

int main() {
    char original[MAX_LEN];
    char duplicate[MAX_LEN];
    char forbidden[] = "cheat";  

    cout << "Enter student document (paragraph): ";
    cin.getline(original, MAX_LEN);

    
    int len = getLength(original);
    copyString(original, duplicate);

    
    int letters = 0, digits = 0, symbols = 0;
    int freq[26] = {0};

    for (int i = 0; i < len; i++) {
        if ((original[i] >= 'a' && original[i] <= 'z') ||
            (original[i] >= 'A' && original[i] <= 'Z')) {
            letters++;
            char lower = (original[i] >= 'A' && original[i] <= 'Z') ? original[i] + 32 : original[i];
            freq[lower - 'a'] ++;
        } else if (original[i] >= '0' && original[i] <= '9') digits++;
        else symbols++;
        
    }

    
    int wordCount = 0;
    bool inWord = false;
    for (int i = 0; i < len; i++) {
        if (original[i] != ' ' && !inWord) {
            inWord = true;
            wordCount++;
        } else if (original[i] == ' ') {
            inWord = false;
        }
    }

    
    bool forbiddenFound = containsSubstring(original, forbidden);

    
    cout << "\n--- PLAGIARISM & LINGUISTIC REPORT ---\n";

    cout << "Status: ";
    if (forbiddenFound)
        cout << "REJECTED (Forbidden keywords found)\n";
    else if (wordCount > 50)
        cout << "SUSPICIOUS (Word limit threshold)\n";  
    else
        cout << "ACCEPTED\n";

    cout << "Document Length: " << len << " characters\n";
    cout << "Word Count: " << wordCount << "\n";

    cout << "\nCharacter Distribution:\n";
    cout << "Letters: " << letters << " | Digits: " << digits << " | Symbols: " << symbols << "\n";

    char reversed[MAX_LEN];
    copyString(original, reversed);
    reverseWords(reversed);
    cout << "\nProcessed Text (Reversed Words): " << reversed << endl;

    return 0;
}

