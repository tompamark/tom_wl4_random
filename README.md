# `tom_wl4_random` package
ROS 2 C++ package.  [![Static Badge](https://img.shields.io/badge/ROS_2-Humble-34aec5)](https://docs.ros.org/en/humble/)

A package két nodeból áll. A /battery_simulator node szimulált akkumulátoradatokat generál: az akkuszintet százalélkban csökkenti a megfelelő mértékben, majd ezeket a sensor_msgs/msg/BatteryState típusú topicban hirdeti. A /battery_warning node feliratkozik erre a battery_status topicra, és ha az akksi töltöttsége 20% aláá csökken, egy figyelmeztetést küld egy std_msgs/msg/String típusú battery_alert topicban. A figyelmeztetést terminálban is kiírja. 
Megvalósítás ROS 2 Humble alatt.

## Packages and build

It is assumed that the workspace is `~/ros2_ws/`.

### Clone the packages
``` r
cd ~/ros2_ws/src
```
``` r
git clone https://github.com/tompamark/tom_wl4_random
```

### Build ROS 2 packages
``` r
cd ~/ros2_ws
```
``` r
colcon build --packages-select tom_wl4_random --symlink-install
```

<details>
<summary> Don't forget to source before ROS commands.</summary>

``` bash
source ~/ros2_ws/install/setup.bash
```
</details>

``` r
ros2 launch tom_wl4_random launch_example1.launch.py
```

