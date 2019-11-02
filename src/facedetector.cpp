#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include "facedetectcnn.h"
#include "facedetector.h"

namespace py = pybind11;

FaceDetector::FaceDetector() {

}

py::array_t<int> FaceDetector::detect(py::array_t<unsigned char> image) {

	// Initialize detection buffer
	int *pResults = NULL;
	unsigned char *pBuffer = (unsigned char *)std::malloc(DETECT_BUFFER_SIZE);

	if (!pBuffer) {
		throw std::exception("Cannot alloc buffer.\n");
	}

	// Get image size
	const auto &buff_info = image.request();
	const auto &shape = buff_info.shape;

	if (shape.size() != 3 || shape[2] != 3) {
		throw std::exception("Invalid image size.\n");
	}

	pResults = facedetect_cnn(pBuffer, (unsigned char*)(buff_info.ptr), shape[1], shape[0], shape[1] * 3);
	int nResults = (pResults ? *pResults : 0);

	auto result_array = py::array_t<int>({nResults, 6});

	for (int k = 0; k < nResults; k++) {
		short *p = ((short*)(pResults + 1)) + 142 * k;
		int x = p[0];
		int y = p[1];
		int w = p[2];
		int h = p[3];
		int confidence = p[4];
		int angle = p[5];

		*result_array.mutable_data(k, 0) = x;
		*result_array.mutable_data(k, 1) = y;
		*result_array.mutable_data(k, 2) = w;
		*result_array.mutable_data(k, 3) = h;
		*result_array.mutable_data(k, 4) = confidence;
		*result_array.mutable_data(k, 5) = angle;
	}

	std::free(pBuffer);

	return result_array;
}
