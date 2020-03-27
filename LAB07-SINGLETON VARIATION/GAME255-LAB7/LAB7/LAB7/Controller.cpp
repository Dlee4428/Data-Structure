#include "Controller.h"

//Declare a static STL vector of Controller Pointers
//Name it _instance
// static vector<Controller*> _instance;
vector<Controller*> Controller::_instance;

Controller::Controller() 
{
	//Check if vector is empty
	if (_instance.empty())
	{
		//Allocate vector memory by reserving the vector Controller locations
		//Use vector's reserve(size) member function
		_instance.reserve(_instance.size());
	}

	cout << "Controller Constructor" << endl;
}

Controller::~Controller() 
{
	cout << "Controller Destructor" << endl; 
}

Controller* Controller::getInstance()
{
	//Check if the vector is less than 4
	if (_instance.size() < 4)
	{
		//Instantiate a temporary auto_ptr for Controller
		auto_ptr<Controller> temp_ptr(new Controller);

		//Push the controller pointer into the vector
		_instance.push_back(temp_ptr.get());

		cout << "Controller " << _instance.size() << " returned" << endl;

	} else { //Else
		cout << "Controller Exists" << endl;

		//Return the last item in the vector
		return _instance.back();
	} 
}