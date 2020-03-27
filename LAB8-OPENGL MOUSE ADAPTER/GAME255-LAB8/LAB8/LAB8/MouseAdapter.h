#ifndef MOUSEADAPTER_H
#define MOUSEADAPTER_H

#include <iostream>
#include <string>

#include "MouseEvent.h"

using namespace std;

class MouseAdapter
{
	public:
		//Mouse Click Adapter Method
		//INSERT CODE HERE
		static void mouseClicked(int button, int state, int x, int y)
		{
			//Declare a string button state
			string btn_state;
			//Set the mouse state to the button and state method parameters
			_mouse->setState(button, state);
			//Set the mouse new position to the x and y coordinate parameters
			_mouse->setNewPos(x, y);
			//If state is equal to GLUT_DOWN
			if (state == GLUT_DOWN)
			{
				//Set the button state to Down
				btn_state = "Down ";
			}
			//Else
			else
			{
				//Set the button state to Up
				btn_state = "Up ";
			}
			//Print output similar to mine!
			cout << "Mouse " << btn_state << "At " << _mouse->getX() << " " << _mouse->getY() << endl;
		}

		//Mouse Move Adapter Method
		//INSERT CODE HERE
		static void mouseMoved(int x, int y)
		{
			//Set the mouse old position to be the "new" position, which is stored in _mouse
			_mouse->setOldPos(_mouse->getX(), _mouse->getY() );
			//Set the new mouse position to the x and y coodinate parameters
			_mouse->setNewPos(x, y);
			//Print Mouse Drag Button
			printf("Mouse Drag Button ");
			//If _mouse button clicked is left
			if (_mouse->isLeft())
			{
				//Print left
				cout << "Left " << endl;
			} 
			//Else if _mouse button clicked is right
			else if (_mouse->isRight())
			{
				//Print right
				cout << "Right " << endl;
				
			}
			//Else
			else
			{
				//Print Middle
				cout << "Middle " << endl;
				
			}
			//Print output similar to mine!
			cout << "\tFrom " << _mouse->getOldX() << " " << _mouse->getOldY() << endl;
			cout << "\tTo " << _mouse->getX() << " " << _mouse->getY() << endl;
			cout << "\tChange " << _mouse->getDiffX() << " " << _mouse->getDiffY() << endl;
		}

	private:
		static MouseEvent* _mouse;
};

//Instantiate the MouseEvent _mouse instance variable
//INSERT CODE HERE
MouseEvent* MouseAdapter::_mouse = new MouseEvent();
#endif