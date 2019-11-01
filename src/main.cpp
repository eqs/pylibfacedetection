#include <pybind11/pybind11.h>

namespace py = pybind11;

int add(int i, int j) {
	return i + j;
}

PYBIND11_MODULE(clibfacedetection, m) {
	m.doc() = "Python binding of libfacedetection";

	m.def("add", &add, "example function");
}
