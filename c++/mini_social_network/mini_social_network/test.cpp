#include"socialNetwork.h"
using namespace std;


int main()
{
    socialNetwork sn;
    sn.registerUser("jerey", "12345");
    User* puser=sn.loginUser("jerey", "12345");
    puser->addFriend("Tom");
    puser->postState("sleep");
    sn.saveTofile();
    return 0;

}