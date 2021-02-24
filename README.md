## c_log

在单片机环境中使用，一般不需要动态修改打印等级，也不需要过滤标签、关键字等功能。

## 使用方法

```C
#include "./log.h"

log_content_t g_tLogger;
char buf[1024];

log_output_desc_t g_tDesc = {
    .pBuffer = buf,
    .wBufferSize = sizeof(buf),
};

int mian(void)
{
    LOG_INIT(&g_tLogger, &g_tDesc, NULL);
    LOG_SET_FORMAT(&g_tLogger, LOG_OPT_FUNCTION_NAME   |
                               LOG_OPT_LINE_NO         |
                               LOG_OPT_DATETIME        |
                               LOG_OPT_LEVEL_NAME);

    LOG_DEBUG(&g_tLogger, "this is debug\n");
    LOG_INFO(&g_tLogger, "%s\n", "this is info");
    LOG_WARN(&g_tLogger, "[%s]\n", "this is warn");
    LOG_ERROR(&g_tLogger, "%s, xxxxxx\n", "this is error");
    LOG_CRITICAL(&g_tLogger, "this is critical\n");
}
```

输出结果

```C
2021-02-24 15:40:56 main 21 [DEBUG] this is debug
2021-02-24 15:40:56 main 22 [INFO] this is info
2021-02-24 15:40:56 main 23 [WARN] [this is warn]
2021-02-24 15:40:56 main 24 [ERROR] this is error, xxxxxx
2021-02-24 15:40:56 main 25 [CRITICAL] this is critical
```

### 设置模块级别的最小打印等级

在`include "log.h"` 前定义 `LOG_MODULE_LEVEL_ERROR`, 在该文件下小于此等级的日志不会输出

类似的还有其它宏定义

```c
//#define LOG_MODULE_LEVEL_DEBUG
//#define LOG_MODULE_LEVEL_INFO
//#define LOG_MODULE_LEVEL_WARN
#define LOG_MODULE_LEVEL_ERROR
//#define LOG_MODULE_LEVEL_CRITICAL
#include "./log.h"
```

输出结果

```c
2021-02-24 15:40:40 main 24 [ERROR] this is error, xxxxxx
2021-02-24 15:40:40 main 25 [CRITICAL] this is critical
```

### 设置全局的打印最小打印等级

在 `log_cfg.h` 中定义 `LOG_MINIMUM_LEVEL` 的值, 对于所有`logger`, 小于此等级的日志不会输出

```c
#define LOG_MINIMUM_LEVEL   L_INFO
```
