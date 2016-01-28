#pragma once
/*
Class representing the Nodes implemented in Jeff Hawkings Hierarchial Temporal Memory ... 

Functionality :
	Has to send and receive byte streams. 
	byte steams will be implemented as a char array containing 0 or 1 
	Message sending will try to draw inspiration from the way sockets work. 
	Sending will simply be an abstractions, we will just pass pointers to memory block, no actual memory sending. 

	All byte messages will be 100 char long array ... No need for the overhead of the vector or matrix class. 



*/

class htm_node
{
public:
	htm_node();
	~htm_node();
};

