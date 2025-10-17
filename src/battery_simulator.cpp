#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/battery_state.hpp"
#include <chrono>
#include <cstdlib>

using namespace std::chrono_literals;

class BatterySimulator : public rclcpp::Node
{
public:
  BatterySimulator() : Node("battery_simulator"), battery_level_(100.0)
  {
    publisher_ = this->create_publisher<sensor_msgs::msg::BatteryState>("battery_status", 10);
    timer_ = this->create_wall_timer(1000ms, std::bind(&BatterySimulator::timer_callback, this));
    RCLCPP_INFO(this->get_logger(), "Battery simulator node started.");
  }

private:
  void timer_callback()
  {
    float decrease = static_cast<float>(rand() % 20) / 10.0;
    battery_level_ = std::max(0.0f, battery_level_ - decrease);

    auto msg = sensor_msgs::msg::BatteryState();
    msg.percentage = battery_level_ / 100.0;
    msg.power_supply_status = sensor_msgs::msg::BatteryState::POWER_SUPPLY_STATUS_DISCHARGING;

    publisher_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "Battery level: %.1f%%", battery_level_);
  }

  rclcpp::Publisher<sensor_msgs::msg::BatteryState>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  float battery_level_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<BatterySimulator>());
  rclcpp::shutdown();
  return 0;
}
