//
// Created by yop on 30/03/17.
//

#ifndef EMBEDDED_UTILS_H
#define EMBEDDED_UTILS_H

#include <iostream>
// [TODO] Check that
/*#define assert(exp) if(!exp) {\
                           std::cout << "[EE] Error in file " << __FILE__ << " line " << __LINE__ << " : assertion failed !";\
                         abort(-1);}\
*/


#ifdef __DEBUG__

#ifdef __GALILEO__
#define PrintDbg(text) std::cout<< "[Dbg] In file " << __FILE__ << " line " << __LINE__  << " : " << text << std::endl;
#define InitPlatform() Init_Galileo();
#else
#ifdef __ARDUINO__

void printDebugArduino(char * )

#define PrintDbg(text) std::cout<< "[Dbg] In file " << __FILE__ << " line " << __LINE__  << " : " << text << std::endl;
#define InitPlatform() Init_Arduino();
#endif

#else
#define PrintDbg(text)
#endif



#endif //EMBEDDED_UTILS_