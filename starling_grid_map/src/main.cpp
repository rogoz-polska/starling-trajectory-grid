#include "rclcpp/rclcpp.hpp"

#include "starling_grid_map/starling_grid.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Starling Grid map generator started");
  rclcpp::spin(std::make_shared<starling_grid_map::StarlingGrid>());
  rclcpp::shutdown();
  return 0;
}