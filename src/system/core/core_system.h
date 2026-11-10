#ifndef CORE_SYSTEM_H
#define CORE_SYSTEM_H

#include "core.h"

#ifdef __cplusplus
extern "C"
{
#endif
 

CORE_API int get_system_error_message(DWORD error_id, char *target, int max_len);

#ifdef __cplusplus
}
#endif

#endif // CORE_SYSTEM_H
