//
//  TemplStaticArray.h
//  XArrayData
//
//  Created by Thomas Dickerson on 4/14/15.
//  Copyright (c) 2015 StickFigure Graphic Productions. All rights reserved.
//

#ifndef __XArrayData__TemplStaticArray__
#define __XArrayData__TemplStaticArray__

// Slightly more generic extension of http://stackoverflow.com/questions/17627862/c-static-const-array-initialization-in-template-class

template <typename T,T ...Args>
struct XArrayData
{
	static const T Values[sizeof...(Args)];
};

template<size_t N, typename T, constexpr T(&ArrayArgMap)(size_t), T ...Args>
struct _XArrayGenerator
{
	typedef typename _XArrayGenerator<N - 1, T, ArrayArgMap, ArrayArgMap(N), Args...>::Xdata Xdata;
};

template<typename T, constexpr T(&ArrayArgMap)(size_t), T ...Args>
struct _XArrayGenerator<1, T, ArrayArgMap, Args...>
{
	typedef XArrayData<T, ArrayArgMap(1), Args...> Xdata;
};

template<size_t N,typename T, constexpr T(&ArrayArgMap)(size_t)>
struct XArray
{
	typedef typename _XArrayGenerator<N,T,ArrayArgMap>::Xdata Xdata;
};

template <typename T, T ...Args>
const T XArrayData<T,Args...>::Values[sizeof...(Args)] = { Args... };

#endif /* defined(__XArrayData__TemplStaticArray__) */
