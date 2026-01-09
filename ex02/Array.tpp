#include "Array.hpp"

template<typename T>
Array<T>::Array() : arr(nullptr), n_size(0){
	//std::cout << "Start of DEFAULT constractur" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]()), n_size(n){
	//std::cout << "Start of PARAMETER constractur" << std::endl;
}

template<typename T>
Array<T>::Array(const Array &src){
	this->n_size = src.n_size;
	this->arr = new T[src.n_size];
	for(unsigned int i=0; i < src.n_size; i++){
		this->arr[i] = src.arr[i];
	}
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &src){
	if(this != &src){
		delete [] this->arr;
		this->n_size = src.n_size;
		this->arr = new T[src.n_size];
		for(unsigned int i=0; i < src.n_size; i++){
			this->arr[i] = src.arr[i];
		}
	}
	return (*this);
}

template<typename T>
Array<T>::~Array(){
	delete [] this->arr;
}

template<typename T>
T &Array<T>::operator[](const unsigned int pos){
	if(pos >= this->n_size){
		throw std::out_of_range("Error: Out of the array range");
	}
	return this->arr[pos];
}

template<typename T>
unsigned int Array<T>::size() const{
	return (this->n_size);
}