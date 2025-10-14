# RobotProgramming template for ROS 2 Humble

This repository can be thought as a template for a multi-platform ROS 2 workspace.

It ships with a `pixi` configuration that should be working on `x86-64 Linux`
and `osx-arm64` platforms
(for `Windows` users, we suggest using `WSL2`, along with Pixi).

## Quickstart

### Remove `.git` folder

If you wish to use this repository as your ROS 2 workspace, we suggest removing the `.git` folder
to decouple your project from this repository.

First clone this repository and then remove the `.git` folder

```bash
git clone https://github.com/SapienzaRobotProgramming2526/template_multiplatform_ros2_builder.git ros2_ws
cd ros2_ws
rm -rf .git
```

### Pixi

[Pixi](pixi.sh/latest) is a fast package management tool (alternative to [Anaconda](https://www.anaconda.com/)).
It provides means to reliably create isolated environments with locked versioning,
good for reproducibility.

Install the latest version of Pixi by typing

```bash
curl -fsSL https://pixi.sh/install.sh | sh
```

or, if your system doesn't have `curl`, you can use `wget` with

```bash
wget -qO- https://pixi.sh/install.sh | sh
```

For additional info on the capabilities of Pixi, please refer to the [docs](https://pixi.sh/latest/)

### Initialization

Once Pixi is installed, you can install the environment by `cd`-ing in the
project repository and by typing

```bash
pixi shell
```

During the first execution, Pixi will download and setup the environment, while also
configuring the environment variables to active it.

**Remember that each time you open a new shell, `pixi shell` command should be
called to activate the environment.**

### Building and running ROS 2 applications

After activating the environment, you virtually have all the `ROS2 Humble` framework
available. Remember that this repository acts like a colcon workspace and thus,
requires all packages to be located in the `src` directory.

As an example, we will follow the [official tutorial](https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Creating-Your-First-ROS2-Package.html) to create a new package.

First, get in the `src` directory

```bash
cd src
```

Then create a new CMake package and corresponding node
(in this case, a package named `hello_world_pkg` and a node called `hello_world_node`)

```bash
ros2 pkg create --build-type ament_cmake --node-name hello_world_node hello_world_pkg
```

Finally, get back to the root of the workspace

```bash
cd ../
```

and run colcon to build the package

```bash
colcon build
```

## Advanced Infos

As you may (probably not) know, ROS 2 uses [DDS](https://en.wikipedia.org/wiki/Data_Distribution_Service) to implement the publisher-subscriber pattern.
Interestingly enough, several logical networks can share the same physical network,
provided that they all share the same ROS `Domain ID`.
Specifically, ROS 2 nodes on the same domain can freely discover and
send messages to each other, while ROS 2 nodes on different domains cannot.
By default, all ROS 2 nodes use a domain ID 0.
You can imagine our faces when we discovered this fact in the hard-way, by running a publisher-subscriber exercise
in front of a lot of students, connected in the same WiFi network.

To avoid interference between different groups of nodes,
either you manually change the `ROS_DOMAIN_ID`, hoping that no other student
set the same as yours.

Since the probability of two students select the same ID,
we instead opted for another solution.
Within this repository, we also ship two configuration files
for the fastdds and cyclonedds main middleware(s)
that disable the node discoveries only to the local machine,
solving completely the interference issue.

## Contacts

If you find issues related to the configuration of this repository,
AKA you cannot compile because you are missing some packages or similar,
please contact me at: `giacomini at diag.uniroma1.it`
with prefix `[RP]` on the title of the email.


# NOTE:
In install/ there are all the exectutables created by ''colcon build'' command