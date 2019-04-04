#include "Python.h"
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/arrayobject.h"

#include "MPS_Spoke.hpp"
#include "MPS_Favored.hpp"
#include "MPS_Two_Spoke.hpp"
#include "MPS_Bridson.hpp"

static PyObject* pyspokedarts_core_mps_bridson(PyObject *self, PyObject *args) {
    MPS_Bridson mps;
    Random my_random(num_dim);
    my_random.initiate_random_generator(seed);
    mps.set_rng(&my_random);
    mps.create(num_dim, is_periodic, r, search_type, all_searches_global, perm_ghosts);

    npy_intp dims[2];
    dims[0] = N;
    dims[1] = D;

    PyObject* samples = PyArray_ZEROS(2, dims, NPY_DOUBLE, 0);

    npy_intp idx[2];
    idx[0] = idx[1] = 0;
    double *X = (double *)PyArray_GetPtr(samples, idx);
    for(i = 0; i < N; i++) {
        for(d = 0; d < D; d++) {
            X[i*D+d] = 0;
        }
    }
    return samples;
}

static PyObject* pyspokedarts_core_mps_line(PyObject *self, PyObject *args) {
    MPS_Spoke mps;
    Random my_random(num_dim);
    my_random.initiate_random_generator(seed);
    mps.set_rng(&my_random);
    mps.create(num_dim, is_periodic, r, search_type, all_searches_global, perm_ghosts);

    npy_intp dims[2];
    dims[0] = N;
    dims[1] = D;

    PyObject* samples = PyArray_ZEROS(2, dims, NPY_DOUBLE, 0);

    npy_intp idx[2];
    idx[0] = idx[1] = 0;
    double *X = (double *)PyArray_GetPtr(samples, idx);
    for(i = 0; i < N; i++) {
        for(d = 0; d < D; d++) {
            X[i*D+d] = 0;
        }
    }
    return samples;
}

static PyObject* pyspokedarts_core_mps_favored(PyObject *self, PyObject *args) {
    MPS_Favored mps;
    Random my_random(num_dim);
    my_random.initiate_random_generator(seed);
    mps.set_rng(&my_random);
    mps.create(num_dim, is_periodic, r, search_type, all_searches_global, perm_ghosts);

    npy_intp dims[2];
    dims[0] = N;
    dims[1] = D;

    PyObject* samples = PyArray_ZEROS(2, dims, NPY_DOUBLE, 0);

    npy_intp idx[2];
    idx[0] = idx[1] = 0;
    double *X = (double *)PyArray_GetPtr(samples, idx);
    for(i = 0; i < N; i++) {
        for(d = 0; d < D; d++) {
            X[i*D+d] = 0;
        }
    }
    return samples;
}


static PyMethodDef pyspokedarts_core_methods[] = {
    {"mps_bridson", (PyCFunction)pyspokedarts_core_mps_bridson, METH_VARARGS, ""},
    {"mps_bridson", (PyCFunction)pyspokedarts_core_mps_bridson, METH_VARARGS, ""},
    {"mps_bridson", (PyCFunction)pyspokedarts_core_mps_bridson, METH_VARARGS, ""},
    {NULL, NULL, 0, NULL}
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef module_def = {
    PyModuleDef_HEAD_INIT,
    "pyspokedarts.core",
    "A Python wrapper to the SpokeDarts C++ library.",
    -1,
    nglpy_cuda_core_methods
};

PyMODINIT_FUNC PyInit_core(){
    import_array();
    return PyModule_Create(&module_def);
}
#else
PyMODINIT_FUNC initcore(){
    import_array();
    Py_InitModule("core", nglpy_cuda_core_methods);
}
#endif
