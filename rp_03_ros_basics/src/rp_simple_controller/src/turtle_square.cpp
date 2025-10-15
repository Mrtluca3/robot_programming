#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

#include "turtlesim/msg/pose.hpp"
 

// Allows us to use literals for time units //so I can use H, min, s, ms, us ns es: auto delay =10ms;
using namespace std::chrono_literals;
// Just to be sure that we have pi available on every platform [required up
// c++20]
constexpr float pi = 3.14159265358979323846;

class TurtleSquareNode : public rclcpp::Node {
 public:
  TurtleSquareNode() : Node("turtle_square_node") {
    // Create the publisher for velocity commands [binded to
    // geometry_msgs::msg::Twist message] //ACTUALLY IT SHOULD BE ABLE TO COMPILE ANYWAY  
    // For simplicity, publish on
    // "/turtle1/cmd_vel"
    // TODO here!
    velocity_pub= this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10); //10== numero di messaggi tenuti nel buffer
    //NON CI METTO AUTO velocity_pub : SONO DICHIARATE SOTTOOOOO!!!!


    // Create the subscriber for the turtle pose [binded to turtlesim::msg::Pose
    // message] For simplicity, subscribe to "/turtle1/pose"
    // TODO here!
    position_sub= this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose", 10, 
          std::bind(&TurtleSquareNode::pose_callback, //reference al metodo di callback 
                    this, //puntatore a  mio nodo
                     std::placeholders::_1) //AFTER THIS, THERE ARE THE ARGUMENTS TO PASS TO THE POSE_CALLBACK FUNCTION
                     //first element passed to the callback method is the -1 one, 
                     // so the last element of the subscriber (it is the message of course!): IT IS THE MESSAGE, turtlesim::msg::Pose, PASSATO COME PUNTATORE SMART
          );
    // what is doing?
    // ---------------------------------------------------------
    // position_sub "should be a" Subscriber  at this topic here: "/turtle1/pose" 10  
    // when I recive a message I call the function: pose_callback() 
    // and pull the elements (this che è hidden),
    // so the last element of the subscriber (it is the message of course!): PASSATO in argomento a callback
    // position_sub -> Subscriber  "/turtle1/pose" -->  turtlesim::msg::Pose -->  pose_callback() 

    // ------------------------------
    // Create the timer for the control loop
    // The timer is set to call the timer_callback function every 1millisecond
    // [1ms]: this is A GOOD TIMING IN ROBOT PROGRAMMING
    timer = this->create_wall_timer(
        20ms, std::bind(&TurtleSquareNode::timer_callback, this));
  } //MODIFIED 20MS<-1MS

 private:
  /**
   * Timer callback.
   * Increase the current time by dt and execute the control loop.
   * The control loop is a simple state machine that makes the turtle move in a
   * square trajectory. The machine has two states:
   * - 0: Move forward for side_length meters
   * - 1: Turn right for angle_to_turn radians
   * The completion of each state is verified as follows:
   * - [0-FORWARD] 
   *     If the current time excedes [side_length / trans_vel] then
   * the state is changed to 1 [TURN]
   * - [1-TURN] 
   *     If the current time excedes [angle_to_turn / rot_vel] then the //cioè è laureata!
   * state is changed to 0 [FORWARD]
   * In both cases, reset current_time to 0.
   *
   * The translational velocity [v] and angular velocity [w] are set based on
   * the current state:
   * - [0-FORWARD] : v = trans_vel | w = 0
   * - [1-TURN] : v = 0 | w = rot_vel
   *
   * Once the velocities are set, create a geometry_msgs::msg::Twist message and
   * store the computed velocities accordingly. Remember that, to control the
   * turtle, [v] should be written in the linear.x field and [w] in the
   * angular.z field. Finally, publish the message on the velocity_pub
   * publisher.
   */
  void timer_callback() {
    // Commenting these to prevent unusued variable warning | errors since
    // -Wpedantic is set in the CMake :( float v = 0.0; float w = 0.0;
    float v=0;
    float w=0;
    v=0;
    w=0;

    current_time += dt;
    
    if (state == 0) {
      if (current_time < side_length / trans_vel) { 
        //current time is less than time of "forward moss" continua ad andare dritto
        v = trans_vel;
        w = 0.0;
      } else {
        state = 1; 
        current_time = 0;
        // v=0;
      }
    } else if (state == 1) {
      if (current_time < angle_to_turn / rot_vel) {
        v = 0.0;
        w = rot_vel;
      } else {
        state = 0;
        current_time = 0;
        // w=0;
        
      }
    }

  

    // TODO here!
    //questo!!! serviva!!: create a geometry_msgs::msg::Twist message
    geometry_msgs::msg::Twist velocity_message; //they have a constructor so it is not random (it is class/struct)
    // é redundant do: geometry_msgs::msg::Twist velocity_message = geometry_msg::msg::Twist(v, 0, 0, 0, 0, w); 

    velocity_message.linear.x = v; //store the computed velocities accordingly.
  
    velocity_message.angular.z = w;

    velocity_pub->publish(velocity_message);

  }

  /**
   * Pose callback.
   * Once the turtle pose is received, print the turtle pose on the console
   * using RCLCPP_INFO macro. If you have problems, you might also use std::cout
   */
  void pose_callback(const turtlesim::msg::Pose::SharedPtr msg) {
    // TODO here!
    //totalmente da capire!
    // PostFix 1: for ROLLING users the message is turtlesim_msgs::msg::Pose
    RCLCPP_INFO(this->get_logger(),
     "Turtle pose: x=%f, y=%f, theta=%f", msg->x,
                msg->y, msg->theta);

  }

  // Timer
  rclcpp::TimerBase::SharedPtr timer;
  // Velocity publisher
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr          velocity_pub;
  // Position subscriber
  rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr            position_sub;



  // Simulation parameters
  const float dt = 0.02;  // timer_callback is called every 0.001 seconds [if
                          // changed, remember to change the timer period]
  float current_time = 0.0f;
  bool state = 0;  // 0 forward - 1 turn
  // Trajectory parameters
  float side_length = 2.0;
  float angle_to_turn = pi * 0.5;  // To turn of 90 degrees
  // Pre-set velocities.

  float trans_vel = 1.0;
  float rot_vel = 1.0;
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TurtleSquareNode>());
  rclcpp::shutdown();
  return 0;
}
