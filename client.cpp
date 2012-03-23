/* 
 * File:   main.cpp
 * Author: master
 *
 * Created on April 2, 2010, 12:21 AM
 */

#include "clcon.h"
using namespace std;

/*
 * 
 */


int main (int argc, char** argv)
{
  clcon tosrv1;
  tosrv1.find_server();
  tosrv1.konnect();
  tosrv1.login();
  while (1) tosrv1.talk();
  tosrv1.logout();
  shutdown(tosrv1.sockt,0);
  return (EXIT_SUCCESS);
}
