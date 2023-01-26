#ifndef ITER_H
#define ITER_H

template <typename T>
void testTemplate(T& a) {
  a *= 3;
}

template <typename Array, typename FuncPointer>
void iter(Array* array, int arraySize, FuncPointer functionPointer) {
  for (int i = 0; i < arraySize; ++i) functionPointer(array[i]);
}

#endif