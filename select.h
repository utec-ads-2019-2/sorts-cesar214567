#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

class SelectSort : public Sort {       
    public:
        SelectSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
                
            for (int i=0;i<size;i++){
                int min=elements[i];
                int l=i;
                for (int j=i;j<size;j++ ){
                    if (elements[j]<min){
                        l=j;
                        min =elements[j];
                    }
                }
                elements[l]=elements[i];
                elements[i]=min;
            }
            
            
        }


        inline string name() { return "SelectSort"; }
};

#endif