#include "sendMessage.h"
#include <string.h>
extern char sendMessage(char c[]){
    strcat(c, " message send by library function.");
    return c;
}