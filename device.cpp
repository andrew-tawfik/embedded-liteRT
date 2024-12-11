#include "device.h"
#include <iostream>
#include "edgetpu.h"

/**
 * @class Device
 * @brief Represents an EdgeTPU device, managing its setup and providing access to device details.
 */

/**
 * @brief Constructs a new Device object.
 *
 * Initializes the EdgeTPU manager singleton and sets up the device
 * by retrieving its type and path.
 */
Device::Device()
{
  m_manager = edgetpu::EdgeTpuManager::GetSingleton();
  DeviceSetup();
}

/**
 * @brief Prints the record of the connected EdgeTPU device.
 *
 * Retrieves the device information using `GetRecord()` and outputs
 * the device type (USB or PCI) and connection path to the standard output.
 */
void Device::PrintDeviceRecord() const
{
  std::cout << "Device type: " << (m_device_type == edgetpu::DeviceType::kApexUsb ? "USB" : "PCI")
            << ", Path: " << m_device_path << std::endl;
}

/**
 * @brief Retrieves the enumeration record of the connected EdgeTPU device.
 *
 * Queries the EdgeTPU manager for the list of connected devices.
 * If no devices are detected, outputs a message indicating the absence of devices.
 * Assumes only one device is handled and returns the first device record.
 *
 * @return The enumeration record of the first connected EdgeTPU device.
 */
edgetpu::EdgeTpuManager::DeviceEnumerationRecord Device::GetRecord() const
{
  std::vector<edgetpu::EdgeTpuManager::DeviceEnumerationRecord> devices = m_manager->EnumerateEdgeTpu();
  if (devices.empty())
  {
    std::cout << "No EdgeTpu devices detected." << std::endl;
  }
  return devices[0]; // only dealing with one device
}

/**
 * @brief Sets up the device by retrieving and storing its type and connection path.
 *
 * Uses the device record from `GetRecord()` to initialize `m_device_type` and
 * `m_device_path` member variables.
 */
void Device::DeviceSetup()
{
  edgetpu::EdgeTpuManager::DeviceEnumerationRecord record = GetRecord();
  m_device_type = record.type;
  m_device_path = record.path;
}

/**
 * @brief Gets the device type
 * 
 * Retreives the m_device_type member value
 * @return the type of device connected 
 */
edgetpu::DeviceType Device::GetType() const
{
  return m_device_type;
}

/**
 * @brief Gets the device path
 * 
 * Retreives a string from the m_device_path member variable, represent the path. 
 * @return the path of the connected device
 */
std::string Device::GetPath() const
{
  return m_device_path;
}

/**
 * @brief Opens and returns a shared pointer to the Edge TPU device.
 *
 * This method uses the `EdgeTpuManager` to open a connection to the Edge TPU
 * device specified by the current device type and path.
 *
 * @return A `std::shared_ptr` to the `EdgeTpuContext` representing the opened
 *         Edge TPU device. This pointer can be used to interact with the device.
 */
std::shared_ptr<edgetpu::EdgeTpuContext> Device::OpenDevice() const
{
  return m_manager->OpenDevice(m_device_type, m_device_path); 
}



