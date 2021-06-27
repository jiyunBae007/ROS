#include "ros/ros.h" //contains basic functions of ROS
#include "std_msgs/String.h"  standard message in ROS, contains a string


int main(int argc, char **argv){
    ros::init(argc,argv, "Publisher"); //send argc,argv, name of node(publisher) as arguments
    ros::NodeHandle nh; //create ros node handle

/*create publisher object_ call function advertise in the node handle, 
advertise has two arguments_ name of the topic and queue size(how many messages we can have in queue)
<String> means the type of the message*/
    ros::Publisher topic_pub = nh.advertise<std_msgs::String>("tutorial",1000); 
/*create object called ros rate_how often publish message, set frequency on how often we are going to update
=>loop_rate(1) : publish a message each second*/
    ros::Rate loop_rate(1);  

    while(ros::ok()){
        //create message
        std_msgs::String msg; //create message object
        msg.data="Hello World!"; //put some data

        topic_pub.publish(msg); //publishes the message to the topic tutorial
        ros::spinOnce(); //checks for any callbacks or if anything new happened neened to react to
        loop_rate.sleep();
    }

    return 0;
    
}
