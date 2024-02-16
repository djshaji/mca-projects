/* Some useful defines
*/

#ifndef UTIL_H
#define UTIL_H

#define INFO (...) info(__FILE__, __LINE__, __func__, __VA_ARGS__);
#define HERE printf("%s [%d]: %s ()\n", __FILE__, __LINE__, __func__);
#define IN printf(">> %s [%d]: %s ()\n", __FILE__, __LINE__, __func__);
#define OUT printf("<< %s [%d]: %s ()\n", __FILE__, __LINE__, __func__);
#endif // UTIL_H