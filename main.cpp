#include <iostream>
#include "device.h"
#include "detection.h"
#include "model.h"
#include "tensorflow/lite/interpreter.h"
#include "tensorflow/lite/kernels/register.h"
#include "tensorflow/lite/model.h"
#include "edgetpu.h"

int main()
{
  Device coral;
  coral.PrintDeviceRecord();
  auto tpu_context = coral.OpenDevice();
  return 0;
}
