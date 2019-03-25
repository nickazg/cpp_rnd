#include <iostream>
#include <Python.h>

// Callable Function
char * hello(char * what){
    std::cout << "hello" << what << std::endl;
}

// Python wrapper
static PyObject * hello_wrapper(PyObject * self, PyObject * args)
{
  char * input;
  char * result;
  PyObject * ret;

  // parse arguments
  if (!PyArg_ParseTuple(args, "s", &input)) {
    return NULL;
  }

  // run the actual function
  result = hello(input);

  // build the resulting string into a Python object.
  ret = PyString_FromString(result);
  free(result);

  return ret;
}

// Symbol table register
static PyMethodDef HelloMethods[] = {
 { "hello", hello_wrapper, METH_VARARGS, "Say hello" },
 { NULL, NULL, 0, NULL }
};

// Init the function
PyMODINIT_FUNC inithello(void)
{
  (void) Py_InitModule("hello", HelloMethods);
}