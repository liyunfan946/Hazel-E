@echo off
:: 清理之前的构建目录
if exist build (
    echo 清理之前的构建目录...
    rmdir /s /q build
)

:: 创建新的构建目录
echo 创建新的构建目录...
mkdir build

cd build

:: 生成Visual Studio 2022项目文件
echo 生成Visual Studio 2022项目文件...
"C:\Program Files\CMake\bin\cmake.exe" .. -G "Visual Studio 17 2022"

if %errorlevel% neq 0 (
    echo 错误: 生成项目文件失败
    pause
    exit /b %errorlevel%
)

echo 项目文件生成成功！
echo 请在Visual Studio 2022中打开 build\Hazel-E.sln 继续开发
pause
