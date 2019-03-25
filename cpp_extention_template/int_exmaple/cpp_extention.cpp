#include <iostream>

// Python extention requirements
#include <Python.h>

// Callable Function
int func_call(int arg){
    
    int return_calc = arg * 1000;
    
    std::cout << return_calc << std::endl;
    
    return return_calc;
}

// Python wrapper
static PyObject * func_wrapper(PyObject * self, PyObject * args)
{
  int input;
  int result;
  PyObject * ret;

  // parse arguments as int https://docs.python.org/2.0/ext/parseTuple.html
  if (!PyArg_ParseTuple(args, "i", &input)) {
    return NULL;
  }

  // run the actual function
  result = func_call(input);

  // build the resulting string into a Python object. https://docs.python.org/2/c-api/int.html
  // https://docs.python.org/2/c-api/arg.html?highlight=py_buildvalue#c.Py_BuildValue
  ret = Py_BuildValue("i", result);

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