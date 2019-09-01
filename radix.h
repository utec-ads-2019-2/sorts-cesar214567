#ifndef RADIX_H
#define RADIX_H

#include "sort.h"
#include <queue>
#include <math.h>      


class RadixSort : public Sort {       
    public:
        RadixSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            int max=elements[0];
            vector<queue<int>> vector_de_stacks(10);
            for(int i=0;i<size;i++){
                if (elements[i]>max){
                    max=elements[i];
                }
            }
            int contador=0;
            while(max%10!=0 or max!=0){
                contador+=1;
                max/=10;
            }
            for (int i=0;i<contador;i++){
                for(int j=0;j<size;j++){
                    int calculo=elements[j]/(pow(10,i));
                    vector_de_stacks[calculo%10].push(elements[j]);
                }


                int contadorfinal=0;
                for (int j=0;j<10;j++){
                    while (!vector_de_stacks[j].empty()){
                        elements[contadorfinal]=vector_de_stacks[j].front();
                        vector_de_stacks[j].pop();
                        contadorfinal+=1;
                    }
                }

            }
        }

        inline string name() { return "RadixSort"; }
};

#endif