#include "ros/ros.h"
#include "node1/random_target.h"
#include <math.h>


// function for generating a random number between 2 numbers [M,N]
double randMToN(double M, double N) 
{ 
	return M + (rand() / ( RAND_MAX / (N-M) ) ) ;
 }

bool randTarget (node1::random_target::Request &req, 
			node1::random_target::Response &res){
   // generate random number between [-6,6] for x and y
   res.pos_x = randMToN(-6.0, 6.0);
   res.pos_y = randMToN(-6.0, 6.0);
   return true;
}

int main(int argc, char **argv)
{
   // Initialize the node, setup the NodeHandle for handling the communication with the ROS
   // system
   ros::init(argc, argv, "exercise1");
   ros::NodeHandle n;

   // define the service 'random_target'
   ros::ServiceServer service= n.advertiseService("/target", randTarget);
   ros::spin();

   return 0;
}
