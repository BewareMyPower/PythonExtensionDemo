#include <Python.h>
#include <stdio.h>

PyObject* f(PyObject*, PyObject* o) {
    double x = PyFloat_AsDouble(o);
    double y = x + 100;
    printf("%.2lf + 100.00 = %.2lf\n", x, y);
    return PyFloat_FromDouble(y);
}

static PyMethodDef methods[] = {
    { "f", (PyCFunction) f, METH_O, nullptr },
    { nullptr, nullptr, 0, nullptr }
};

static PyModuleDef py_module = {
    PyModuleDef_HEAD_INIT,
    "xyz",
    "Test module by xyz",
    0,
    methods
};

PyMODINIT_FUNC PyInit_xyz() {
    return PyModule_Create(&py_module);
}
