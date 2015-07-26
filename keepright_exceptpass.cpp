/* Author: Tyler Mobray
   Filename: car.cpp
   Date: Feb. 7 2014
   For Math Modeling Contest 2014

   This class, Car, has two attributes: Speed and Position.
   These are both integer values and are used to determine whether a car should
   slow down, keep at its current speed, or attempt to pass another car on
   a Road (which may be another class, or maybe just an array in main().)
   Speed is a simple integer between 55 and 75.
   Position consists of a two-element array, where element 0 is the lane the 
   Car is in, and element 1 is the specific cell (or position in that lane).

   It has methods:

   Car(): this constructor method randomly assigns a speed and position to the
          Car object on the Road (that is, in the array).
   set_speed(int difference): this adds the value of difference to the speed attribute.
   check_speed(): returns value of speed variable
   check_position: returns an array with the values present in position array
   set_position(int lane, int position): changes element 0 to the value of
   the lane parameter, and changes element 1 to the value of the position parameter.

   is_stopped(): returns true if car is stopped, false otherwise (probably won't implement, unless we figure out
                   how to simulate accidents.)

blargh

*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <cmath>

using namespace std;

class Car
{
public:

  Car();
  void set_speed(int difference);
  void set_position(int new_lane, int new_spot);
  int check_speed();
  int check_lane();
  int check_place();
  bool is_stopped();
  void stop_car();
  void start_car();
  bool is_empty();
  void set_empty(bool yesno);

private:

  int speed;
  int position[2];
  bool stopped;
  bool empty;
};

Car::Car()
{
  srand(time(NULL));
  speed = (rand()%21)+55; //21 is gotten by doing (high_end - low_end)+1
  /*  if(speed > 75)
    speed = speed - (speed - 75);
  if(speed < 55)
  speed = speed + (75-speed);*/
  //position[0] = (rand()%(num_roads - 1));
  //position[1] = (rand()%(num_cells - 1));
  stopped = false;
  empty = false;
}

void Car::set_speed(signed int difference)
{
  speed = speed + difference;
}

void Car::set_position(int new_lane, int new_spot)
{
  if(new_lane == -1 && new_spot > -1)
    position[1] = new_spot;
  if(new_lane > -1 && new_spot == -1)
    position[0] = new_spot;
  else
    {
      position[0] = new_lane;
      position[1] = new_spot;
    }
}

int Car::check_speed()
{
  int thing_me;
  thing_me = speed;
  return thing_me;
}

int Car::check_lane()
{
  return position[0];
}

int Car::check_place()
{
  return position[1];
}

bool Car:: is_stopped()
{
  return stopped;
}

void Car::stop_car()
{
  stopped = true;
}

void Car::start_car()
{
  stopped = false;
}

bool Car::is_empty()
{
  return empty;
}

void Car::set_empty(bool yesno)
{
  empty = yesno;
}

//set_empty is SANE in this one!!!
int main()
{
  /*  int traffic;
  int slowdowns = 0;
  cout<< "SIM: KEEP RIGHT EXCEPT TO PASS" << endl;
  cout<< "Light or Heavy Traffic? (1 or 2?): " << endl;
  traffic = 2;
  const int NUM_LANES = 4;
  const int NUM_SPOTS = 132;
  int num_cars;
  int num_placed = 0;
  cout << "DECLARE ROAD" << endl;
  Car* road[NUM_LANES][NUM_SPOTS]; //Road *declared*
  cout << "Calc traffic" << endl;
  if(traffic == 1)
    {
      num_cars = floor(.15*(NUM_LANES*NUM_SPOTS));
      cout << "num_cars is: " << num_cars << "traffic choice: " << traffic << endl;
    }
  if(traffic == 2)
    {
      num_cars = floor(.70*(NUM_LANES*NUM_SPOTS));
      cout << "num_cars is: " << num_cars << "traffic choice: " << traffic << endl;
    }
    cout << "traffic calculated!" << endl; */
  Car* mitzy = new Car();
  cout << "Car is named Mitzy. Mitzy is going: " << mitzy -> check_speed() << endl;
  cout << "Car is in lane: " << mitzy -> check_lane() << endl;
  cout << "Car is in position: " << mitzy -> check_place() << endl;
  cout << "Empty state of car is: " << mitzy -> is_empty() << endl;
  cout << "Start state of car is: " << mitzy -> is_stopped() << endl;

  Car* nitzy = new Car();
  cout << "Car is named Nitzy. Nitzy is going: " << nitzy -> check_speed() << endl;
  cout << "Car is in lane: " << nitzy -> check_lane() << endl;
  cout << "Car is in position: " << nitzy -> check_place() << endl;
  cout << "Empty state of car is: " << nitzy -> is_empty() << endl;
  cout << "Start state of car is: " << nitzy -> is_stopped() << endl;
  delete mitzy;
  delete nitzy;
  return 0;
}
