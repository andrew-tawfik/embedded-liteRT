#include <iostream>
#include "edgetpu.h"

int main()
{
  // Get the singleton instance of EdgeTpuManager.
  edgetpu::EdgeTpuManager* manager = edgetpu::EdgeTpuManager::GetSingleton();

  if (!manager) {
    std::cerr << "Failed to get the Edge TPU Manager instance." << std::endl;
    return 1;
  }

  // Enumerate connected Edge TPU devices.
  std::vector<edgetpu::EdgeTpuManager::DeviceEnumerationRecord> devices = manager->EnumerateEdgeTpu();

  if (devices.empty()) {
    std::cout << "No Edge TPU devices detected." << std::endl;
  } else {
    std::cout << "Edge TPU devices detected:" << std::endl;
    for (const auto& device : devices) {
      std::cout << "Device Type: " << (device.type == edgetpu::DeviceType::kApexUsb ? "USB" : "PCI")
                << ", Path: " << device.path << std::endl;
    }
  }

  return 0;
}
