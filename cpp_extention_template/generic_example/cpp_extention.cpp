#include <iostream>

// Python extention requirements
#include <Python.h>

// Callable Function
char * func_call(char * arg){
    std::cout << arg << std::endl;
}

// Python wrapper
static PyObject * func_wrapper(PyObject * self, PyObject * args)
{
  char * input;
  char * result;
  PyObject * ret;

  // parse arguments https://docs.python.org/2.0/ext/parseTuple.html
  if (!PyArg_ParseTuple(args, "s", &input)) {
    return NULL;
  }

  // run the actual function
  result = func_call(input);

  // build the resulting string into a Python object.
  ret = PyString_FromString(result);
  free(result); // deallocates a block of memory (used when result is a pointer *)

  return ret;
}

// Symbol table register
static PyMethodDef HelloMethods[] = {
 { "func_name", func_wrapper, METH_VARARGS, "Desc" },
 { NULL, NULL, 0, NULL }
};

// Init the function
PyMODINIT_FUNC initfunc_module(void)
{
  (void) Py_InitModule("func_module", HelloMethods);
}