#include <iostream>
using namespace std;

// Returns the length of a C-style string (excluding null terminator)
int stringLength(const char* s) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

// Copies source string into destination (including null terminator)
void stringCopy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Compares two strings lexicographically
// Returns -1 if s1 < s2, 0 if equal, 1 if s1 > s2
int stringCompare(const char* s1, const char* s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i]) return -1;
        if (s1[i] > s2[i]) return 1;
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0') return 0;
    if (s1[i] == '\0') return -1;
    return 1;
}

// Sorts a 2D array of strings using Selection Sort
void selectionSort(char arr[][100], int size) {
    int startScan, minIndex;
    char temp[100];
    for (startScan = 0; startScan < size - 1; startScan++) {
        minIndex = startScan;
        for (int index = startScan + 1; index < size; index++) {
            if (stringCompare(arr[index], arr[minIndex]) < 0) {
                minIndex = index;
            }
        }
        // Swap only if a smaller element was found
        if (minIndex != startScan) {
            stringCopy(temp, arr[startScan]);
            stringCopy(arr[startScan], arr[minIndex]);
            stringCopy(arr[minIndex], temp);
        }
    }
}

int main() {
    const int NUM_NAMES = 20;
    // List of names in "Last, First" format
    char names[NUM_NAMES][100] = {
        "Collins, Bill", "Smith, Bart", "Allen, Jim",
        "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
        "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
        "Looney, Joe", "Wolfe, Bill", "James, Jean",
        "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
        "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
        "Pike, Gordon", "Holland, Beth"
    };

    // Sort the names alphabetically
    selectionSort(names, NUM_NAMES);

    // Print the sorted list
    for (int i = 0; i < NUM_NAMES; i++) {
        cout << names[i] << endl;
    }
    return 0;
}
