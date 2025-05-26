# 修复事件头文件包含路径
$files = @(
    "Hazel_E\src\event\KeyEvent.h",
    "Hazel_E\src\event\MouseEvent.h",
    "Hazel_E\src\event\WindowEvent.h",
    "Hazel_E\src\event\ApplicationEvent.h"
)

foreach ($file in $files) {
    $content = Get-Content -Path $file -Raw -Encoding UTF8
    $newContent = $content -replace '#include "event/Event.h"', '#include "Event.h"'
    $newContent = $newContent -replace '#include "event//Event.h"', '#include "Event.h"'
    Set-Content -Path $file -Value $newContent -Encoding UTF8
}

Write-Host "已修复事件头文件包含路径"
