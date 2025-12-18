#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename TR, typename TL, typename TF>
void iter(TR *array, TL length, TF func){
	for(TL i = 0; i < length; i++){
		func(array[i]);
	}
}

#endif