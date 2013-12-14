// Autogenerated file for halcon type HEllipse

#include "pyhirsch.h"

static void
PyHirschEllipse_dealloc(PyHirschEllipse* self)
{
    PyObject_Del(self);
}

static int
PyHirschEllipse_init(PyHirschEllipse *self, PyObject *args, PyObject */*kwds*/)
{
    double centerX,centerY,ra,rb,phi=0;
    PyHirschEllipse *rect;

    if (PyArg_ParseTuple(args,"(dd)dd|d",&centerX,&centerY,&ra,&rb,&phi)) 
        self->Ellipse = Halcon::HEllipse(Halcon::HPoint2D(centerX,centerY),
                                               ra,rb,phi);
                                               
    else if (PyArg_ParseTuple(args,"O",&rect)
             && PyHirschEllipse_Check(rect)
             ) {
        self->Ellipse = Halcon::HEllipse(rect->Ellipse);
        Py_DECREF(rect);
    }
    else
        // Empty rectangle
        self->Ellipse = Halcon::HEllipse();

    PyErr_Clear();

    return 0;
}

#include "hellipse_autogen_methods_declarations.i"

static PyMethodDef PyHirschEllipse_methods[] = {
#include "hellipse_autogen_methods_list.i"
    {NULL}  /* Sentinel */
};

PyObject *PyHirschEllipse_FromHEllipse(Halcon::HEllipse Ellipse)
{
    PyHirschEllipse *v = (PyHirschEllipse*)PyObject_New(PyHirschEllipse, &PyHirschEllipseType);
    v->Ellipse = Halcon::HEllipse(Ellipse);
    return (PyObject*)v;
}

static PyObject *
PyHirschEllipse_str(PyObject *ob)
{
    PyHirschEllipse *self = (PyHirschEllipse *)ob;
    Halcon::HPoint2D Center = self->Ellipse.Center();
    double ra = self->Ellipse.Ra();
    double rb = self->Ellipse.Rb();
    double phi = self->Ellipse.Phi();
    PyObject *Tuple = Py_BuildValue("Oddd",
                                    PyHirschPoint2D_FromHPoint2D(Center),
                                    ra,rb,phi);
    PyObject *Ret = PyObject_Str(Tuple);
    Py_DECREF(Tuple);

    return Ret;
}

PyTypeObject PyHirschEllipseType = {
    PyObject_HEAD_INIT(NULL)
    0,                         /*ob_size*/
    "Halcon.Rectangle",      /*tp_name*/
    sizeof(PyHirschEllipse), /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    (destructor)PyHirschEllipse_dealloc,       /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    PyHirschEllipse_str,                         /*tp_str*/
    0,                         /*tp_as_number*/
    0,        /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    PyHirschEllipse_str,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT,        /*tp_flags*/
    "PyHirschEllipse",        /* tp_doc */
    0,		               /* tp_traverse */
    0,		               /* tp_clear */
    0,		               /* tp_richcompare */
    0,		               /* tp_weaklistoffset */
    0,		 /* tp_iter */
    0,         /* tp_iternext */
    PyHirschEllipse_methods,  /* tp_methods */
    0,                         /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)PyHirschEllipse_init,          /* tp_init */
    0,                         /* tp_alloc */
    PyType_GenericNew,         /* tp_new */
};


void PyHirschEllipseAddToModule(PyObject *m)
{
    Py_INCREF(&PyHirschEllipseType);
    if (PyType_Ready(&PyHirschEllipseType) < 0)
        return;
    PyModule_AddObject(m, "HEllipse", (PyObject *)&PyHirschEllipseType);
}
