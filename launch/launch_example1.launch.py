from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='tom_wl4_random',
            executable='battery_simulator',
            name='battery_simulator',
            output='screen'
        ),
        Node(
            package='tom_wl4_random',
            executable='battery_warning',
            name='battery_warning',
            output='screen'
        )
    ])