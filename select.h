#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

class SelectSort : public Sort {       
    public:
        SelectSort(void *elements, size_t size) : Sort(elements, size) {}

        void execute(void (*compare)(void*, int, int)) {
            int *array = (int *)elements;
            for(int i = 0; i < size-1; i++){
                int min_index = i;
                int j = i + 1;
                while (j < size){
                    min_index = (array[j] < array[min_index])? j:i;
                }
                compare(elements, i, min_index);
            }
        }

        inline string name() { return "SelectSort"; }
};

#endif