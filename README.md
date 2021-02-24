## c_log
## 使用方法

```C
#include "./log.h"

static log_content_t s_tLogger;
char buf[1024];

log_output_desc_t tDesc = {
    .pBuffer = buf,
    .wBufferSize = sizeof(buf),
};

int mian(void)
{
    LOG_INIT(&s_tLogger, &tDesc, &s_nUser);
    LOG_SET_FORMAT(&s_tLogger, LOG_OPT_FUNCTION_NAME |
                               LOG_OPT_DATETIME |
                               LOG_OPT_LEVEL_NAME);

    LOG_DEBUG(&s_tLogger, "this is debug\n");
    LOG_INFO(&s_tLogger, "%s\n", "this is info");
    LOG_WARN(&s_tLogger, "[%s]\n", "this is warn");
    LOG_ERROR(&s_tLogger, "%s, xxxxxx\n", "this is error");
    LOG_CRITICAL(&s_tLogger, "this is critical\n");
}
```

输出结果

```C
2021-02-24 15:11:56 main [DEBUG] this is debug
2021-02-24 15:11:56 main [INFO] this is info
2021-02-24 15:11:56 main [WARN] [this is warn]
2021-02-24 15:11:56 main [ERROR] this is error, xxxxxx
2021-02-24 15:11:56 main [CRITICAL] this is critical
```

### 设置模块级别的最小打印等级

在`include "log.h"` 前定义 `LOG_MODULE_MINIMUM_ERROR`, 小于此等级的日志不会输出
类似的还有

```c
//#define LOG_MODULE_MINIMUM_DEBUG
//#define LOG_MODULE_MINIMUM_INFO
//#define LOG_MODULE_MINIMUM_WARN
#define LOG_MODULE_MINIMUM_ERROR
//#define LOG_MODULE_MINIMUM_CRITICAL
#include "./log.h"
```

输出结果

```c
2021-02-24 15:14:35 main [ERROR] this is error, xxxxxx
2021-02-24 15:14:35 main [CRITICAL] this is critical
```

### 设置全局的打印最小打印等级

在 `log_cfg.h` 中定义 `LOG_MINIMUM_LEVEL` 的值,小于此等级的日志不会输出

```c
#define LOG_MINIMUM_LEVEL   L_INFO
```
