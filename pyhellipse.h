// Autogenerated file for halcon type HEllipse
#ifndef PYHELLIPSE_H
#define HELLIPSE_H

#include <Python.h>
#include <HalconCpp.h>

PyObject *PyHirschEllipse_FromHEllipse(Halcon::HEllipse Ellipse);

typedef struct {
    PyObject_HEAD;
    Halcon::HEllipse Ellipse;
} PyHirschEllipse;

#define PyHirschEllipse_Check(op) \
    PyObject_TypeCheck(op, &PyHirschEllipseType)

void PyHirschEllipseAddToModule(PyObject *m);

PyAPI_DATA(PyTypeObject) PyHirschEllipseType;

#endif