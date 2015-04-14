
#include <cstddef>
#include <cmath>
#include <cstdio>
#include <iostream>
#include "TemplStaticArray.h"

constexpr int zero(size_t i){
	return 0;
}

constexpr int id(size_t i){
	return i;
}

int main(){
	typedef XArray<5, int, zero> test;
	typedef XArray<5, int, id> test2;
	for(size_t i = 0; i < 5; i++){
		std::cout << test::Xdata::Values[i] << " "
		<< test2::Xdata::Values[i] << std::endl;
	}
}
