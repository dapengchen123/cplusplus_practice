//
// Created by hp on 20/03/2021.
//

#include <pybind11/pybind11.h>

int add(int i, int j) {
    return i + j;
}
PYBIND11_MODULE(example, m){
    m.doc() = "pybind11 example plugin";
    m.def("add", &add, "A function which add two number");
}

