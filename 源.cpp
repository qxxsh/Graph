#include<iostream>
using namespace std;

#define m 16 
#define NULLKEY 0 //单元为空的标记

struct HashTable {
    int  key;
};

void CreateHash(HashTable HT[], int n);
int SearchHash(HashTable HT[], int key);

int main()
{
    int value, key;
    int result;
    int i, j, n;
    HashTable HT[m];
    for (i = 0; i < m; i++)
        HT[i].key = 0;
    cin >> n;
    if (n > m) return 0;
    CreateHash(HT, n);
    cin >> key;
    result = SearchHash(HT, key);
    if (result != -1)
        cout << "search success，The key is located in " << result + 1;
    else
        cout << "search failed";
    return 0;
}


void CreateHash(HashTable HT[], int n)  {
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        while (HT[k % m].key != NULLKEY) {
            k++;
        }
        HT[k % m].key = k;
    }
}

int SearchHash(HashTable HT[], int key) {
    int start = key % m;
    while (HT[key % m].key != NULLKEY) {
        if (HT[key % m].key == key) return key % m;
        else key++;

        if (start == key % m)return -1;
    }
    return -1;
}

