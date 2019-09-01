#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

class QuickSort : public Sort {       
    public:
        QuickSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            quicksort(elements,0,size-1);
        }
        
    template <typename T>
    int divide( T* array,int inicio, int final){
        int derecha;
        int izquierda;
        T pivot;
        T temp;

        pivot=array[inicio];
        derecha=final;
        izquierda=inicio;

        while (izquierda<derecha){
            while (array[derecha]>pivot){
                derecha--;
            }
            while (izquierda<derecha and array[izquierda]<=pivot ){
                izquierda++;
            }
            if (izquierda< derecha){
            temp=array[izquierda ];
            array[izquierda]=array[derecha];
            array[derecha]=temp;

            }
        }
        temp = array[derecha];
        array[derecha] = array[inicio];
        array[inicio] = temp;
        return derecha;

        }

    template <typename T>
    void quicksort (T* array, int inicio, int final){
        int pivot;
        if (inicio<final){
            pivot=divide(array,inicio,final);

            quicksort(array,inicio, pivot-1);

            quicksort(array,pivot+1,final);
        }
    }


        inline string name() { return "QuickSort"; }
};

#endif