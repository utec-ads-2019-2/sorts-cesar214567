#ifndef COUNTING_H
#define COUNTING_H

#include "sort.h"
#include <algorithm>
#include <vector>


class CountingSort : public Sort {       
    public:
        CountingSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            vector<int> vector_temporal(size);
            for (int i=0;i<size;i++){
                vector_temporal[i]=elements[i]; 
                
            }
            int max,min,tamano;
            max=*max_element(vector_temporal.begin(),vector_temporal.end());
            min=*min_element(vector_temporal.begin(),vector_temporal.end());
            tamano=max-min+1;  
            vector<int> vector_retorno(tamano,0);
            for (int i=0;i<size;i++){
                vector_retorno[vector_temporal[i]-min]+=1;
            }   
            int contador=0;
            for (int i=0;i<tamano;i++){
                for (int j=0;j<vector_retorno[i];j++){
                    elements[contador]=i+min;
                    contador+=1;
                }
            }
                        
            
            
            }

        inline string name() { return "CountingSort"; }
};

#endif