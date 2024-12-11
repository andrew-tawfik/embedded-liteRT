// device.h
//
// Provides the `Device` class, which manages the setup and interaction
// with an EdgeTPU device, including retrieving and printing device records.

#include "edgetpu.h"

#ifndef DEVICE_H
#define DEVICE_H

/**
 * @class Device
 * @brief Manages interactions with an EdgeTPU device.
 *
 * The `Device` class handles the initialization, setup, and record
 * retrieval for an EdgeTPU device. It assumes only one device is connected.
 */
class Device
{
private:
  edgetpu::EdgeTpuManager* m_manager; // Singleton instance of EdgeTPU manager
  edgetpu::DeviceType m_device_type; // Type of connected device (USB or PCI)
  std::string m_device_path;         // Path to connected device

  /**
   * @brief Sets up the device by retrieving its type and connection path.
   */
  void DeviceSetup();

public:
  /**
  * @brief Constructs a new Device object.
  *
  * Initializes the EdgeTPU manager and sets up the device.
  */
  Device();


  /**
   * @brief Prints the record of the connected EdgeTPU device.
   *
   * Retrieves the device record and outputs the device type (USB or PCI) and
   * its connection path to the standard output.
   */
  void PrintDeviceRecord() const;

  /**
 * @brief Retrieves the enumeration record of the connected EdgeTPU device.
 *
 * Queries the EdgeTPU manager for connected devices. If no devices are
 * detected, outputs a message. Assumes only one device is handled.
 *
 * @return The record of the first connected EdgeTPU device.
 */
  edgetpu::EdgeTpuManager::DeviceEnumerationRecord GetRecord() const;

  edgetpu::DeviceType GetType() const;
  std::string GetPath() const;

  std::shared_ptr<edgetpu::EdgeTpuContext> OpenDevice() const;

};



#endif //DEVICE_H
