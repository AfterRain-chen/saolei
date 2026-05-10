学习笔记：在 VS Code 中配置多语言项目的要点总结

1. Visual Studio 与 VS Code 的差异：
   - Visual Studio 提供图形化项目管理和自动构建系统，适合快速开发。
   - VS Code 更轻量，需要手动配置 tasks.json（构建任务）和 launch.json（调试配置），但自由度更高，适合深入理解编译流程。

2. C/C++ 混合编译：
   - 可以统一使用 g++ 编译 C 和 C++ 文件，避免链接错误。
   - 也可以分别用 gcc 和 g++ 编译，再用 g++ 链接。
   - 若 C++ 调用 C 函数，需在 C 的头文件中加上 extern "C" 来避免名称修饰（name mangling）问题。

3. tasks.json 配置：
   - 为每种语言单独写构建任务（如 build-c、build-cpp、build-java 等）。
   - 若希望一次性编译多个语言文件，可使用复合任务（dependsOn 多个子任务）。

4. launch.json 配置：
   - 每种语言写独立调试配置，指定程序路径和参数。
   - 对于 C/C++，需设置 preLaunchTask 来确保调试前自动构建。

5. 不使用复合任务时的建议：
   - 可在命令面板（Ctrl+Shift+P → Run Task）中选择不同任务。
   - 或者修改 tasks.json 中的 isDefault 属性，切换默认任务。

6. Visual Studio 的优势与 VS Code 的价值：
   - VS 自动处理编译、链接、调试，适合快速开发。
   - VS Code 虽需手动配置，但能帮助深入理解构建流程，适合学习和跨平台开发。

7. 建议与扩展：
   - 整理通用模板（tasks.json 和 launch.json），便于复用。
   - 尝试使用 CMake 或 Makefile 管理多语言项目。
   - 利用 VS Code 插件扩展功能，如 CMake Tools、CodeLLDB 等。

—— 记录者：jan
