#define LOG_MODULE_MINIMUM_ERROR
#include "./log.h"

static log_content_t s_tContent;
static int32_t s_nUser = 1000;

int main(void)
{
    char buf[1024];

    log_output_desc_t tDesc = {
        .pBuffer = buf,
        .wBufferSize = sizeof(buf),
    };

    LOG_INIT(&s_tContent, &tDesc, &s_nUser);
    LOG_SET(&s_tContent,
            LOG_OPT_FUNCTION_NAME |
            LOG_OPT_DATETIME |
            LOG_OPT_LEVEL_NAME|
            LOG_OPT_FILE_NAME);

    LOG_DEBUG(&s_tContent, "hello\n");
    LOG_INFO(&s_tContent, "dd\n");
    LOG_WARN(&s_tContent, "vv\n");
    LOG_ERROR(&s_tContent, "55\n");
    LOG_CRITICAL(&s_tContent, "66\n");

    return 0;
}
