#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/battery_state.hpp"
#include "std_msgs/msg/string.hpp"

class BatteryWarning : public rclcpp::Node
{
public:
  BatteryWarning() : Node("battery_warning")
  {
    subscription_ = this->create_subscription<sensor_msgs::msg::BatteryState>(
      "battery_status", 10,
      std::bind(&BatteryWarning::battery_callback, this, std::placeholders::_1));

    publisher_ = this->create_publisher<std_msgs::msg::String>("battery_alert", 10);
    RCLCPP_INFO(this->get_logger(), "Battery warning node started.");
  }

private:
  void battery_callback(const sensor_msgs::msg::BatteryState::SharedPtr msg)
  {
    float percentage = msg->percentage * 100.0;
    if (percentage < 20.0)
    {
      auto alert = std_msgs::msg::String();
      alert.data = "⚠️ Low battery warning! (" + std::to_string(percentage) + "%)";
      publisher_->publish(alert);
      RCLCPP_WARN(this->get_logger(), "%s", alert.data.c_str());
    }
    else
    {
      RCLCPP_INFO(this->get_logger(), "Battery OK (%.1f%%)", percentage);
    }
  }

  rclcpp::Subscription<sensor_msgs::msg::BatteryState>::SharedPtr subscription_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<BatteryWarning>());
  rclcpp::shutdown();
  return 0;
}
