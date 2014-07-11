#include <Python.h>
#include <stdbool.h>

#include <aerospike/as_query.h>

#include "client.h"
#include "scan.h"

#undef TRACE
#define TRACE()

AerospikeScan * AerospikeScan_Select(AerospikeScan * self, PyObject * args, PyObject * kwds)
{
  TRACE();
  
  as_scan_select_init(&self->scan, 100);

  int nbins = (int) PyTuple_Size(args);
  for ( int i = 0; i < nbins; i++ ) {
    PyObject * py_bin = PyTuple_GetItem(args, i);
    if ( PyString_Check(py_bin) ) {
      TRACE();
      char * bin = PyString_AsString(py_bin);
      as_scan_select(&self->scan, bin);
    }
    else {
      TRACE();
    }
  }

  Py_INCREF(self);
  return self;
}