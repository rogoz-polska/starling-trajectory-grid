#include <string>
#include <vector>
#include "rclcpp/rclcpp.hpp"
#include <cmath>
#include <memory>
#include <utility>


#include "grid_map_msgs/msg/grid_map.hpp"
#include "grid_map_msgs/msg/grid_map_info.hpp"
#include <grid_map_ros/grid_map_ros.hpp>


#include "starling_grid_map/starling_grid.hpp"



using namespace std;
using std::placeholders::_1;
using namespace starling_grid_map;

StarlingGrid::StarlingGrid(): Node("starling_grid"), call_back_duration(1000ms)
{   

    gridmap_pub_ = this->create_publisher<grid_map_msgs::msg::GridMap>("/starling/gridmap", 10); 

    gridmap_info_pub_ = this->create_publisher<grid_map_msgs::msg::GridMapInfo>("/starling/gridmap_info", 10);

    // xxxx_sub_ = this->create_subscription<xxx_msgs::msg::xxx>("/starling/xxxxx", 10, std::bind(&StarlingGrid::xxxxx_callback, this, _1));
    
    timer_ = this->create_wall_timer(call_back_duration, std::bind(&StarlingGrid::timer_callback, this));
    // odom_tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);

    grid_map_msg = std::make_shared<sensor_msgs::msg::GridMap>();
    gridmap_info_msg = std::make_shared<nav_msgs::msg::GridMapInfo>();
  

    grid_map::GridMap map({"elevation"});
    map.setFrameId("map");
    map.setGeometry(grid_map::Length(100.0, 50.0), 0.5);
    RCLCPP_INFO(
      node->get_logger(),
      "Created map with size %f x %f m (%i x %i cells).",
      map.getLength().x(), map.getLength().y(),
      map.getSize()(0), map.getSize()(1));
}

void StarlingGrid::timer_callback()
{

  auto time = node->now();

 

  // Publish grid map.
  map.setTimestamp(time.nanoseconds());
  std::unique_ptr<grid_map_msgs::msg::GridMap> message;
  message = grid_map::GridMapRosConverter::toMessage(map);
  gridmap_pub_>publish(std::move(message));
  RCLCPP_INFO_THROTTLE(node->get_logger(), "Grid map published.");

  // RCLCPP_INFO(this->get_logger(), "duration: %f", call_back_duration_s);
  
}




   

