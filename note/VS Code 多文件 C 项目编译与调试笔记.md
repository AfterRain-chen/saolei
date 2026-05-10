VS Code 多文件 C 项目编译与调试笔记

1. 项目结构
代码
SAOLEI/
├── .vscode/
│   ├── launch.json      ← 调试配置
│   └── tasks.json       ← 编译任务配置
└── src/
    ├── test.c           ← 主函数入口
    ├── move.c           ← 功能实现
    └── move.h           ← 函数声明

2. 命令行编译方法
在 src 目录下：
bash
gcc test.c move.c -o test

在项目根目录下：
bash
gcc src/test.c src/move.c -o test
常见错误：No such file or directory → 说明路径不对，要么进入 src，要么加上 src/ 前缀。

3. tasks.json 配置（自动编译）
json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "build SAOLEI",
      "type": "shell",
      "command": "gcc",
      "args": [
        "${workspaceFolder}/src/*.c",
        "-o",
        "${workspaceFolder}/saolei.exe"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "problemMatcher": ["$gcc"]
    }
  ]
}
作用：按 Ctrl+Shift+B 自动编译所有 .c 文件。

技巧：用 *.c 通配符避免每次新增文件都要修改配置。

4. launch.json 配置（自动调试）
json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Debug SAOLEI",
      "type": "cppdbg",
      "request": "launch",
      "program": "${workspaceFolder}/saolei.exe",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "miDebuggerPath": "E:\\VSCode\\MinGW\\mingw64\\bin\\gdb.exe",
      "preLaunchTask": "build SAOLEI"
    }
  ]
}

关键点：

program → 指定编译生成的 .exe 文件路径
miDebuggerPath → 指定 GDB 的安装路径
不要用 pipeTransport，否则会报找不到 bash.exe 的错误

5. 一键编译与调试流程
按 Ctrl+Shift+B → 自动编译所有源文件

按 F5 → 自动运行并进入调试模式

可以设置断点、查看变量、单步执行

🎯 总结
tasks.json 管理编译任务

launch.json 管理调试任务

配合使用 → 实现 VS Code 的“一键编译 + 一键调试”

用 *.c 通配符或 Makefile → 避免频繁修改配置



那怎么编译多语言？
有两种方式：

1. 每种语言单独运行一次
在命令面板（Ctrl+Shift+P → 输入 Run Task）里选择你要运行的任务，比如 build-cpp 或 build-java。

或者在 tasks.json 里把不同任务轮流设为默认，然后用 Ctrl+Shift+B。

这种方式适合你只想编译某一种语言的文件。

2. 用复合任务（一次性全部编译）
如果你希望 Ctrl+Shift+B 一次性编译所有语言，就需要写复合任务，把多个子任务串联起来。

这样就不用每次手动切换任务。