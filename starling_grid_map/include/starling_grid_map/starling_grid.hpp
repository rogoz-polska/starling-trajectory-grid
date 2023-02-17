#ifndef __STARLING_GRID_HPP__
#define __STARLING_GRID_HPP__

#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "grid_map_msgs/msg/grid_map.hpp"
#include "grid_map_msgs/msg/grid_map_info.hpp"
// #include "tf2_ros/transform_broadcaster.h"
// #include "nav_msgs/msg/path.hpp"




namespace starling_grid_map
{
    using namespace std;
    using duration_ms = std::chrono::duration<int, std::milli>;
    
    

    class StarlingGrid : public rclcpp::Node
    {
    public:
        StarlingGrid();

    private:

     
        void timer_callback();
      
        

        rclcpp::Publisher<grid_map_msgs::msg::GridMap>::SharedPtr gridmap_pub_;
        rclcpp::Publisher<grid_map_msgs::msg::GridMapInfo>::SharedPtr gridmap_info_pub_;

        // rclcpp::Subscription<xxxx::msg::xxxxx>::SharedPtr xxxxxxxx_sub_;

        // std::unique_ptr<tf2_ros::TransformBroadcaster> odom_tf_broadcaster_;
        // rclcpp::TimerBase::SharedPtr timer_;

        std::shared_ptr<grid_map_msgs::msg::GridMap> grid_map_msg;
        std::shared_ptr<grid_map_msgs::msg::GridMapInfo> gridmap_info_msg;

    };

}


#endif // __STARLING_GRID_NODE_HPP__