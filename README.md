# pylibfacedetection

[![Latest PyPI version](https://img.shields.io/pypi/v/pylibfacedetection.svg)](https://pypi.python.org/pypi/pylibfacedetection)

[![Latest Travis CI build status](https://travis-ci.com/eqs/pylibfacedetection.png)](https://travis-ci.com/eqs/pylibfacedetection)

`pylibfacedetection` is a Python binding of libfacedetection (https://github.com/ShiqiYu/libfacedetection).

# Usage

A minimal example:

```python
import cv2
from pylibfacedetection import FaceDetector

filepath = './path/to/image'

image = cv2.imread(filepath)

detector = FaceDetector()
results = detector.detect(image)

image_out = image.copy()

for result in results:
   x, y, w, h, p, a = result
   if p > 50:
       cv2.rectangle(image_out, (x, y), (x + w, y + h),
                     (0, 255, 0), thickness=4)

print(results)

cv2.namedWindow('result', cv2.WINDOW_NORMAL)
cv2.imshow('result', image_out)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

# Installation

```sh
pip install pylibfacedetection
```

# Licence

BSD

# Authors

eqs (https://www.eqseqs.work)

