#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

        void add(Entry* entry) {
            if (index == 0) {
                array[0] = *entry;
                index++;
            return;
            }

            if (index == SIZE && entry->score <= array[index - 1].score) {
                cout << entry->name<< "'s score is too low to be added!" << endl;
                return;
            }

            if (index < SIZE) {
                index++;
            }

            int i = index - 1;

            while (i > 0 && array[i - 1].score < entry->score) {
                array[i] = array[i - 1]; 
                i--;
            }

            array[i] = *entry;
        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};