#include <iostream>
#include <vector>


using namespace std;

void printArray(vector<int> stream) {
    for(int i = 0; i < stream.size(); i++)
        cout << stream[i] << " ";
    cout << endl;
}

void selectKItems(vector<int> stream, int k) {
    vector<int> reservoir(k, 0);
    for(int i = 0; i < k; i++)
        reservoir[i] = stream[i];
    for(int i = k + 1; i < stream.size(); i++) {
        int j = rand() % (i + 1);
        if(j < k)
            reservoir[j] = stream[i];
    }
    printArray(reservoir);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    vector<int> stream(arr, arr + 12);
    int k = 1;
    selectKItems(stream, k);
}

