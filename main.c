//#define LOG_MODULE_MINIMUM_ERROR
#include "./log.h"

log_content_t g_tLogger;
char buf[1024];

log_output_desc_t g_tDesc = {
        .pBuffer = buf,
        .wBufferSize = sizeof(buf),
};

int main(void)
{
    LOG_INIT(&g_tLogger, &g_tDesc, NULL);
    LOG_SET_FORMAT(&g_tLogger,
                    LOG_OPT_FUNCTION_NAME   |
                    LOG_OPT_LINE_NO         |
                    LOG_OPT_DATETIME        |
                    LOG_OPT_LEVEL_NAME);

    LOG_DEBUG(&g_tLogger, "this is debug\n");
    LOG_INFO(&g_tLogger, "%s\n", "this is info");
    LOG_WARN(&g_tLogger, "[%s]\n", "this is warn");
    LOG_ERROR(&g_tLogger, "%s, xxxxxx\n", "this is error");
    LOG_CRITICAL(&g_tLogger, "this is critical\n");

    return 0;
}
