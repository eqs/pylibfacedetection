#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#define DETECT_BUFFER_SIZE 0x20000

namespace py = pybind11;

class FaceDetector {
public:
	FaceDetector();

	template <typename T>
	py::array_t<int> detect(py::array_t<T> image);
}
