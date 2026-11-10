#include "core_system.h"


int get_system_error_message(DWORD error_id, char *target, int max_len)
{
    if (!target || max_len <= 0)
        return 0;
    LPSTR msg_buf = NULL;
    size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                 NULL, error_id, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&msg_buf, 0, NULL);
    if (size > 0 && msg_buf != NULL)
    {
        if (size >= 2 && msg_buf[size - 2] == '\r')
            msg_buf[size - 2] = '\0';
        else if (size >= 1 && msg_buf[size - 1] == '\n')
            msg_buf[size - 1] = '\0';
        strncpy(target, msg_buf, max_len - 1);
        target[max_len - 1] = '\0';
        LocalFree(msg_buf);
        return (int)strlen(target);
    }
    return _snprintf(target, max_len, "Error Windows: %lu", error_id);
}
