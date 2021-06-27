#include "ros/ros.h"
#include "std_msgs/String.h"

//when we subscribe to the topic we call this callback function_write message to log 
void writeMsgToLog(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("The message that we received was: %s", msg->data.c_str());
}
int main(int argc, char **argv){
    ros::init(argc,argv,"Subscriber");
    ros::NodeHandle nh;

/*create a subscriber object (called topic_sub)
function subscribe takes three arguments 
(topic name_same as the topic name setting in publisher_node.cpp , queue size, callback function)
callback function is that call every time see that a new message has been incoming*/
    ros:: Subscriber topic_sub = nh.subscribe("tutorial",1000, writeMsgToLog);

    ros::spin(); //finish up the main function(loops and waits for incoming messages)



    return 0;
}
