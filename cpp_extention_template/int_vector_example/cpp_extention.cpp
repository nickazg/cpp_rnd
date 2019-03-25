#include <iostream>
#include <vector>

// Python extention requirements
#include <Python.h>

// Callable Function
std::vector<int> func_call(int arg){
    
    std::vector<int> ret_vec;

    for (int i = 0; i < arg; i++){
      ret_vec.push_back(i);
    }

    return ret_vec;
}
// Converts an int vector to Python list
PyObject* vectorToList_Int(const std::vector<int> &data) {
  PyObject* listObj = PyList_New( data.size() );
	if (!listObj) throw std::logic_error("Unable to allocate memory for Python list");
	for (unsigned int i = 0; i < data.size(); i++) {        
		PyObject *num = Py_BuildValue("i", data[i]);
		if (!num) {
			Py_DECREF(listObj);
			throw std::logic_error("Unable to allocate memory for Python list");
		}
		PyList_SET_ITEM(listObj, i, num);
	}
	return listObj;
}

// Python wrapper
static PyObject * func_wrapper(PyObject * self, PyObject * args)
{
  int input;
  std::vector<int> result;
  PyObject * ret;

  // parse arguments as int https://docs.python.org/2.0/ext/parseTuple.html
  if (!PyArg_ParseTuple(args, "i", &input)) {
    return NULL;
  }

  // run the actual function
  result = func_call(input);

  // build the resulting string into a Python object. https://docs.python.org/2/c-api/int.html
  // https://docs.python.org/2/c-api/arg.html?highlight=py_buildvalue#c.Py_BuildValue
  ret = vectorToList_Int(result);

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