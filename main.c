#define LOG_MODULE_MINIMUM_ERROR
#include "./log.h"

static log_content_t s_tLogger;

int main(void)
{
    char buf[1024];

    log_output_desc_t tDesc = {
        .pBuffer = buf,
        .wBufferSize = sizeof(buf),
    };

    LOG_INIT(&s_tLogger, &tDesc, NULL);
    LOG_SET_FORMAT(&s_tLogger,
                    LOG_OPT_FUNCTION_NAME |
                    LOG_OPT_DATETIME |
                    LOG_OPT_LEVEL_NAME);

    LOG_DEBUG(&s_tLogger, "this is debug\n");
    LOG_INFO(&s_tLogger, "%s\n", "this is info");
    LOG_WARN(&s_tLogger, "[%s]\n", "this is warn");
    LOG_ERROR(&s_tLogger, "%s, xxxxxx\n", "this is error");
    LOG_CRITICAL(&s_tLogger, "this is critical\n");

    return 0;
}
