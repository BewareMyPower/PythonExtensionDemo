#include <Python.h>
#include <stdio.h>
#include <stdlib.h>

PyObject* f(PyObject* ignored, PyObject* o) {
    double x = PyFloat_AsDouble(o);
    double y = x + 100;
    printf("%.2lf + 100.00 = %.2lf\n", x, y);
    return PyFloat_FromDouble(y);
}

static PyMethodDef methods[] = {
    { "f", (PyCFunction) f, METH_O, NULL },
    { NULL, NULL, 0, NULL }
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
