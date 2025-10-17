from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='battery_monitor',
            executable='battery_simulator',
            name='battery_simulator',
            output='screen'
        ),
        Node(
            package='battery_monitor',
            executable='battery_warning',
            name='battery_warning',
            output='screen'
        )
    ])