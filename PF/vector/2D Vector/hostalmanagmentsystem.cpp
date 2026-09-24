#include <iostream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

struct UserID
{
    int ID;
    string Name;
    int Phone_Number;
};
struct Room
{
    int floor_number;
    int Room_Number;
    bool isBooked = false;
    UserID quest;
};

class hostalmanagmentsystem
{
private:
    const static int Total_Floor = 12;
    const static int Total_Room = 20;
    Room Building [Total_Floor][Total_Room];
public:
    


};

int main()
{
    
    return 0;
}