#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include "facedetector.h"

namespace py = pybind11;

PYBIND11_MODULE(clibfacedetection, m) {
	m.doc() = "Python binding of libfacedetection";

	py::class_<FaceDetector>(m, "FaceDetector")
		.def(py::init<>())
		.def("detect", (py::array_t<int> (FaceDetector::*)(const py::array_t<int> &)) &FaceDetector::detect);
};
