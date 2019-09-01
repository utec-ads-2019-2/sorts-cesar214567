#ifndef SHELL_H
#define SHELL_H

#include "sort.h"

class ShellSort : public Sort {       
    public:
        ShellSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            for (int i=size/2;i>0;i/=2){
                for (int j=i;j<size;j++){
                    int temporal= elements[j];
                    int k;
                    for (k=j;k>=i && elements[k-i]>temporal;k-=i){
                        elements[k]=elements[k-i];
                    }
                    elements[k]=temporal;
                }
            }
        }       

        inline string name() { return "ShellSort"; }
};

#endif