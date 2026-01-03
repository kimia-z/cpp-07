#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename TR, typename TF>
void iter(TR *array, const size_t length, TF func){
	for(size_t i = 0; i < length; i++){
		func(array[i]);
	}
}

#endif