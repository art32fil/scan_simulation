#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv) {
	ros::init(argc,argv,"controller");
	ros::NodeHandle n;
	ros::Publisher p = n.advertise<geometry_msgs::Twist>("/cmd_vel",100);
	ros::Rate lr(20);
	std::cout << "+---------------------------------------------------------+" << std::endl;
	std::cout << "|Press Arrow-buttons to controll and Ctrl+C or Esc to exit|" << std::endl;
	std::cout << "+---------------------------------------------------------+" << std::endl;
	while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)||sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)&&sf::Keyboard::isKeyPressed(sf::Keyboard::C)) && ros::ok()) {
		geometry_msgs::Twist mes;
		mes.linear.x  = 0;
		mes.angular.z = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    mes.linear.x  += 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  mes.linear.x  -= 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  mes.angular.z += 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) mes.angular.z -= 1;
		p.publish(mes);
		lr.sleep();
	}
}
