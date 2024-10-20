# Accelerating Inference Speeds of Machine Learning Models on Microcontrollers and Mobile Applications

## 

### Project Overview
This project focuses on developing methods to accelerate the inference speeds of machine learning models, particularly in **resource-constrained environments** like microcontrollers. We leverage **TensorFlow Lite** to ensure efficient model execution and utilize the **Google Edge TPU accelerator** to optimize performance.

### Key Features
- **Microcontroller Optimization**: Targeting resource-limited platforms, ensuring the models can run efficiently with minimal latency.
- **TensorFlow Lite Integration**: Utilizing TensorFlow Lite for model inference, which provides a lightweight solution ideal for embedded devices.
- **Edge TPU Acceleration**: The **Google Edge TPU** is used to further speed up the inference process, enabling faster, more efficient execution of ML models on edge devices.

### Technologies Used
- **TensorFlow Lite**: Lightweight framework for deploying machine learning models on mobile and embedded systems.
- **Google Edge TPU**: A hardware accelerator designed to perform high-speed ML inferencing on the edge.
- **C++/Python**: Programming languages used to build the core inference logic and interaction with hardware accelerators.
- **Embedded Systems Programming**: Optimizing ML models for microcontrollers and mobile devices.

### Project Goals
1. **Accelerating Model Inference**: Develop methods to enhance the performance of ML models on resource-constrained environments.
2. **Hardware Integration**: Leverage hardware like the Google Edge TPU for inference speedup.
3. **Model Optimization**: Utilize techniques such as **quantization** and **model pruning** to improve performance without sacrificing accuracy.

### System Requirements
To replicate this project, the following hardware and software are required:

- **Hardware**:
  - Google Coral USB Accelerator

- **Software**:
  - TensorFlow Lite
  - libcoral (Google Edge TPU library)
  - C++

