#ifndef INSERT_H
#define INSERT_H

#include "sort.h"

class InsertSort : public Sort {       
    public:
        InsertSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            int  actual, j;  
            for (int i = 1; i < size; i++) {  
                actual = elements[i];  
                j = i - 1;  
                while (j >= 0 && elements[j] > actual) {    
                    elements[j + 1] = elements[j];  
                    j = j - 1;  
                }  
                elements[j + 1] = actual;  
            }
        }

        inline string name() { return "InsertSort"; }
};

#endif